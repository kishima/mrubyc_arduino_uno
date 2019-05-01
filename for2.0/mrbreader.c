#include "typedef.h"
#include <stdio.h>

struct mrb_header { // 22 byte
	uint32_t binid; // 52 49 54 45
	uint32_t version; // 30 30 30 36
	uint16_t crc; // bb e0
	uint16_t binsize[2]; // big endian, whole file size
	uint8_t compiler_name[4]; // compiler name
	uint8_t compiler_version[4];
} __attribute__((__packed__));

struct mrb_irep {
	uint32_t sectionid;
	uint8_t sectionlen[4];
	uint32_t ireqversion;

	// irep sections...
	uint8_t ireprecordlen[4];
	uint16_t nlocals;
	uint16_t nregs;
	uint16_t nirep;
	uint8_t ncode[4]; // 26byte
		// iseq code (iseq:opcode/oprand)
	uint16_t npools[2];
	// literal block
		uint8_t literaltype; // 0:str, 1:int, 2:float
		uint16_t literallen;
		char* literaldata;
	uint16_t nsymbol[2];
	// symbol block
		uint16_t symbollen;
		char* symbol;
	// irep record block

	// other record blocks この後ろのセクションはなくてもok
} __attribute__((__packed__));

int b2l(int n) {
	return ((n & 0xff) << 8) + ((n >> 8) & 0xff);
}
int b2l4(const uint8_t* n) {
	return (n[0] << 24) | (n[1] << 16) | (n[2] << 8) | n[3];
}
int b2l2(const uint8_t* n) {
	return (n[0] << 8) | n[1];
}

enum {
	OP_NOP,
	OP_MOVE,
	OP_LOADL,
	OP_LOADI,
	OP_LOADINEG,
	OP_LOADI__1,
	OP_LOADI_0,
	OP_LOADI_1,
	OP_LOADI_2,
	OP_LOADI_3,
	OP_LOADI_4,
	OP_LOADI_5,
	OP_LOADI_6,
	OP_LOADI_7,
	OP_LOADSYM,
	OP_LOADNIL,
	OP_LOADSELF,
	OP_LOADT,
	OP_LOADF,
	OP_JMP = 33,
	OP_JMPIF,
	OP_JMPNOT,
	OP_SEND = 46,
	OP_SENDB,
	OP_ENTER = 51,
	OP_RETURN = 55,
	OP_BREAK = 57,
	OP_ADD = 59,
	OP_ADDI,
	OP_SUB,
	OP_SUBI,
	OP_MUL,
	OP_DIV,
	OP_EQ,
	OP_LT,
	OP_LE,
	OP_GT,
	OP_GE,
	OP_STRING = 79,
	OP_BLOCK = 85,
	OP_METHOD,
	OP_DEF = 93,
	OP_TCLASS = 97,
	OP_EXT1 = 100,
	OP_EXT2,
	OP_EXT3,
	OP_STOP,
};

void parseCode(const uint8_t* p, int codelen) {
	int32_t a = 0;
	int32_t b = 0;
	int32_t c = 0;
	const uint8_t* pstart = p;
	const uint8_t* pend = p + codelen;
	int opext = 0;
	while (p < pend) {
		printf("%3d:%3d ", (int)(p - pstart), *p);
		uint8_t op = *p++;
		//printf("op %d\n", op);
		switch (op) {
			case OP_NOP:
				printf("nop\n");
				break;
			case OP_MOVE:
				a = *p++; b = *p++;
				printf("r[%d] = r[%d]\n", a, b);
				break;
			case OP_LOADL:
				a = *p++; b = *p++;
				printf("r[%d] = lit[%d]\n", a, b);
				break;
			case OP_LOADI:
			case OP_LOADINEG:
				a = *p++; b = *p++;
				if (opext == 2)
					b = (b << 8) + *p++;
				if (op == OP_LOADINEG)
					b = -b;
				printf("r[%d] = %d\n", a, b);
				break;
			case OP_LOADI__1:
			case OP_LOADI_0:
			case OP_LOADI_1:
			case OP_LOADI_2:
			case OP_LOADI_3:
			case OP_LOADI_4:
			case OP_LOADI_5:
			case OP_LOADI_6:
			case OP_LOADI_7:
				a = *p++;
				printf("r[%d] = %d\n", a, op - OP_LOADI_0);
				break;
			case OP_LOADSYM:
				a = *p++; b = *p++;
				printf("r[%d] = sym[%d]\n", a, b);
				break;
			case OP_LOADNIL:
				a = *p++;
				printf("r[%d] = nil\n", a);
				break;
			case OP_LOADSELF:
				a = *p++;
				printf("r[%d] = self\n", a);
				break;
			case OP_LOADT:
			case OP_LOADF:
				a = *p++;
				printf("r[%d] = %s\n", a, op == OP_LOADT ? "true" : "false");
				break;
			case OP_JMP:
				a = *p++; b = (a << 8) + *p++;
				printf("jmp %d\n", b);
				break;
			case OP_JMPIF:
			case OP_JMPNOT:
				a = *p++; b = *p++; c = (b << 8) + *p++;
				if (op == OP_JMPIF)
					printf("jmp %d if r[%d]\n", c, a);
				else
					printf("jmp %d if !r[%d]\n", c, a);
				break;
			case OP_SEND:
				a = *p++; b = *p++; c = *p++;
				if (c)
					printf("r[%d] = r[%d].sym[%d](r[%d]-r[%d])\n", a, a, b, a + 1, a + c);
				else
					printf("r[%d] = r[%d].sym[%d]()\n", a, a, b);
				break;
			case OP_SENDB: // OP_ENTERをチェックして、引数の数が合わなかったらエラーを出す必要がある
				a = *p++; b = *p++; c = *p++;
				if (c)
					printf("r[%d] = r[%d].sym[%d](r[%d]-r[%d]) at block:r[%d]\n", a, a, b, a + 1, a + c, a + c + 1);
				else
					printf("r[%d] = r[%d].sym[%d]() at block:r[%d]\n", a, a, b, a + c + 1);
				break;
			case OP_ENTER: // block parameters
				a = *p++; a = (a << 8) | *p++; a = (a << 8) | *p++;
				printf("enter %d:%d:%d:%d:%d:%d:%d\n", a >> 18, (a >> 13) & 0x1f, (a >> 12) & 1, (a >> 7) & 0x1f, (a >> 2) & 0x1f, (a >> 1) & 1, a & 1);
				break;
			case OP_RETURN:
				a = *p++;
				printf("ret r[%d]\n", a);
				break;
			case OP_BREAK:
				a = *p++;
				printf("break r[%d]\n", a);
				break;
			case OP_ADD:
				a = *p++;
				printf("r[%d] = r[%d] + r[%d]\n", a, a, a + 1);
				break;
			case OP_ADDI:
				a = *p++; b = *p++;
				printf("r[%d] = r[%d] + %d\n", a, a, b);
				break;
			case OP_SUB:
				a = *p++;
				printf("r[%d] = r[%d] - r[%d]\n", a, a, a + 1);
				break;
			case OP_SUBI:
				a = *p++; b = *p++;
				printf("r[%d] = r[%d] + %d\n", a, a, b);
				break;
			case OP_MUL:
				a = *p++;
				printf("r[%d] = r[%d] * r[%d]\n", a, a, a + 1);
				break;
			case OP_DIV:
				a = *p++;
				printf("r[%d] = r[%d] / r[%d]\n", a, a, a + 1);
				break;
			case OP_EQ:
				a = *p++;
				printf("r[%d] = r[%d]==r[%d+1]\n", a, a, a);
				break;
			case OP_LT:
				a = *p++;
				printf("r[%d] = r[%d]<r[%d+1]\n", a, a, a);
				break;
			case OP_LE:
				a = *p++;
				printf("r[%d] = r[%d]<=r[%d+1]\n", a, a, a);
				break;
			case OP_GT:
				a = *p++;
				printf("r[%d] = r[%d]>r[%d+1]\n", a, a, a);
				break;
			case OP_GE:
				a = *p++;
				printf("r[%d] = r[%d]>=r[%d+1]\n", a, a, a);
				break;
			case OP_STRING:
				a = *p++; b = *p++;
				printf("r[%d] = str_dup(lit[%d])\n", a, b);
				break;
			case OP_BLOCK: // make procedure
				a = *p++; b = *p++;
				printf("r[%d] = lamda(irep[%d],L_BLOCK)\n", a, b);
				break;
			case OP_METHOD: // OPCODE(METHOD,     BB)       /* R(a) = lambda(SEQ[b],L_METHOD) */
				a = *p++; b = *p++;
				printf("r[%d] = lamda(irep[%d],L_METHOD)\n", a, b);
				break;
			case OP_DEF: // OPCODE(DEF,        BB)       /* R(a).newmethod(Syms(b),R(a+1)) */
				a = *p++; b = *p++;
				printf("r[%d].newmethod(sym[%d], r[%d])\n", a, b, a + 1);
				break;
			case OP_TCLASS:
				a = *p++;
				printf("r[%d] = target_class\n", a);
				break;
			case OP_STOP:
				printf("stop\n");
				break;
			case OP_EXT1:
			case OP_EXT2:
			case OP_EXT3:
				opext = op - OP_EXT1 + 1;
				printf("OP_EXT%d\n", opext);
				break;
			default:
				printf("!! unsupported op code %d\n", op);
				return;
		}
	}
}

const uint8_t* parseIREP(const uint8_t* p) {
	const uint8_t* beginp = p;
	int lenirep = b2l4(p);
	printf("irep record len: %d\n", lenirep); // ??
	p += 4;
	int nlocals = b2l2(p);
	p += 2;
	int nregs = b2l2(p);
	p += 2;
	int nirep = b2l2(p);
	p += 2;
	printf("%d %d %d\n", nlocals, nregs, nirep);
	
	int codelen = b2l4(p);
	p += 4;
	printf("codelen: %d\n", codelen);
	int align = (int)p & 3;
	if (align) {
		p += 4 - align;
	}

	parseCode(p, codelen);
	p += codelen;
	
	int plen = b2l4(p);
	printf("n literals: %d\n", plen);
	p += 4;
	for (int i = 0; i < plen; i++) {
		uint8_t type = *p;
		uint16_t len = b2l2(p + 1);
		printf("lit[%d] type:%d len:%d ", i, type, len);
		if (type == 0) { // null 終端なし
			for (int j = 0; j < len; j++)
				printf("%c", p[3 + j]);
			printf("\n");
		} else if (type == 1) { // int 文字列
			for (int j = 0; j < len; j++)
				printf("%c", p[3 + j]);
			printf("\n");
		} else if (type == 2) { // float
			for (int j = 0; j < len; j++)
				printf("%c", p[3 + j]);
			printf("\n");
		}
		p += len + 3;
	}
	int symlen = b2l4((uint8_t*)p);
	p += 4;
	printf("n symbols: %d\n", symlen);
	for (int i = 0; i < symlen; i++) {
		uint16_t len = b2l2(p);
		printf("sym[%d] %s\n", i, p + 2);
		p += len + 3; // len + '¥0'
	}
	printf("n ireps: %d\n", nirep);
	for (int i = 0; i < nirep; i++) {
		printf("ireps[%d]\n", i);
		p = parseIREP(p);
	}
	return p;
}

const uint8_t* parseMRB(const uint8_t* p) {
	struct mrb_header* mh = (struct mrb_header*)p;
	printf("%x\n", mh->crc);
	printf("%d\n", b2l(mh->binsize[1]));
	
	p += 22;
	struct mrb_irep* mi = (struct mrb_irep*)p;
	int seclen = b2l(mi->sectionlen[1]); // 0??
	printf("%x %d\n", mi->sectionid, seclen);
	p += 12;

	p = parseIREP(p);

	for (int i = 0;; i++) {
		uint32_t sectionid = b2l4(p);
		p += 4;
		uint32_t sectionlen = b2l4(p);
		p += 4;
		printf("sec %x %x\n", sectionid, sectionlen);
		if (sectionid == 0x454e4400) // == END
			break;
		// 0x4C564152 LVAR
		p += sectionlen - 8;
	}
	return NULL;
}

int main(int argc, char** argv) {
	int maxlen = 1024 * 100;
	uint8_t buf[maxlen];
	FILE* fp = fopen(argv[1], "rb");
	int filelen = fread(buf, 1, maxlen, fp);
	
	parseMRB(buf);

	return 0;
}



