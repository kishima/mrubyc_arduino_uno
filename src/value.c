/*! @file
  @brief
  mruby/c value definitions

  <pre>
  Copyright (C) 2015-2018 Kyushu Institute of Technology.
  Copyright (C) 2015-2018 Shimane IT Open-Innovation Center.

  This file is distributed under BSD 3-Clause License.


  </pre>
*/

#include <stdint.h>
#include <string.h>
#include <assert.h>

#include "micro_vm.h"
#include "value.h"
#include "alloc.h"
#include "class.h"
#include "symbol.h"
#include "c_string.h"
//#include "c_range.h"
//#include "c_array.h"
//#include "c_hash.h"


mrb_object *mrbc_obj_alloc(struct VM *vm, mrb_vtype tt)
{
  mrb_object *ptr = (mrb_object *)mrbc_alloc(vm, sizeof(mrb_object));
  if( ptr ){
    ptr->tt = tt;
  }
  return ptr;
}


mrb_proc *mrbc_rproc_alloc(const char *name)
{
  mrb_proc *ptr = (mrb_proc *)mrbc_raw_alloc(sizeof(mrb_proc));
  if( ptr ) {
    ptr->ref_count = 1;
    ptr->sym_id = str_to_symid(name);
    ptr->next = 0;
  }
  return ptr;
}



//================================================================
/*! compare two mrb_values

  @param  v1	Pointer to mrb_value
  @param  v2	Pointer to another mrb_value
  @retval 0	v1 == v2
  @retval plus	v1 >  v2
  @retval minus	v1 <  v2
*/
int mrbc_compare(const mrb_value *v1, const mrb_value *v2)
{
//  double d1, d2;

  // if TT_XXX is different
  if( v1->tt != v2->tt ) {
    // leak Empty?
    if((v1->tt == MRB_TT_EMPTY && v2->tt == MRB_TT_NIL) ||
       (v1->tt == MRB_TT_NIL   && v2->tt == MRB_TT_EMPTY)) return 0;

    // other case
    return v1->tt - v2->tt;
  }

  // check value
  switch( v1->tt ) {
  case MRB_TT_NIL:
  case MRB_TT_FALSE:
  case MRB_TT_TRUE:
    return 0;

  case MRB_TT_FIXNUM:
  case MRB_TT_SYMBOL:
    return v1->i - v2->i;

  case MRB_TT_CLASS:
  case MRB_TT_OBJECT:
  case MRB_TT_PROC:
    return -1 + (v1->handle == v2->handle) + (v1->handle > v2->handle)*2;

  case MRB_TT_ARRAY:
    return 1;
    //TODO
    //return mrbc_array_compare( v1, v2 );

  case MRB_TT_STRING:
    return 1;
    //TODO
    //return mrbc_string_compare( v1, v2 );

  case MRB_TT_RANGE:
    return 1;
    //TODO
    //return mrbc_range_compare( v1, v2 );

  case MRB_TT_HASH:
    return 1;
    //TODO
    //return mrbc_hash_compare( v1, v2 );

  default:
    return 1;
  }
}


//================================================================
/*!@brief
  Duplicate mrb_value

  @param   v     Pointer to mrb_value
*/
void mrbc_dup(mrb_value *v)
{
  switch( v->tt ){
  case MRB_TT_OBJECT:
  case MRB_TT_PROC:
  case MRB_TT_ARRAY:
  case MRB_TT_STRING:
  case MRB_TT_RANGE:
  case MRB_TT_HASH:
    assert( v->instance->ref_count > 0 );
    assert( v->instance->ref_count != 0xff );	// check max value.
    v->instance->ref_count++;
    break;

  default:
    // Nothing
    break;
  }
}


//================================================================
/*!@brief
  Release object related memory

  @param   v     Pointer to target mrb_value
*/
void mrbc_release(mrb_value *v)
{
  mrbc_dec_ref_counter(v);
  v->tt = MRB_TT_EMPTY;
}


//================================================================
/*!@brief
  Decrement reference counter

  @param   v     Pointer to target mrb_value
*/
void mrbc_dec_ref_counter(mrb_value *v)
{
  //TODO
#if 0
  switch( v->tt ){
  case MRB_TT_OBJECT:
  case MRB_TT_PROC:
  case MRB_TT_ARRAY:
  case MRB_TT_STRING:
  case MRB_TT_RANGE:
  case MRB_TT_HASH:
    assert( v->instance->ref_count != 0 );
    v->instance->ref_count--;
    break;

  default:
    // Nothing
    return;
  }

  // release memory?
  if( v->instance->ref_count != 0 ) return;

  switch( v->tt ) {
  case MRB_TT_OBJECT:	mrbc_instance_delete(v);	break;
  case MRB_TT_PROC:	mrbc_raw_free(v->handle);	break;
  case MRB_TT_ARRAY:	mrbc_array_delete(v);		break;
#if MRBC_USE_STRING
  case MRB_TT_STRING:	mrbc_string_delete(v);		break;
#endif
  case MRB_TT_RANGE:	mrbc_range_delete(v);		break;
  case MRB_TT_HASH:	mrbc_hash_delete(v);		break;

  default:
    // Nothing
    break;
  }
#endif
}


//================================================================
/*!@brief

  convert ASCII string to integer mruby/c version

  @param  s	source string.
  @param  base	n base.
  @return	result.
*/
int32_t mrbc_atoi( const char *s, int base )
{
  int ret = 0;
  int sign = 0;

 REDO:
  switch( *s ) {
  case '-':
    sign = 1;
    // fall through.
  case '+':
    s++;
    break;

  case ' ':
    s++;
    goto REDO;
  }

  int ch;
  while( (ch = *s++) != '\0' ) {
    int n;

    if( 'a' <= ch ) {
      n = ch - 'a' + 10;
    } else
    if( 'A' <= ch ) {
      n = ch - 'A' + 10;
    } else
    if( '0' <= ch && ch <= '9' ) {
      n = ch - '0';
    } else {
      break;
    }
    if( n >= base ) break;

    ret = ret * base + n;
  }

  if( sign ) ret = -ret;

  return ret;
}



//================================================================
/*!@brief
  mrb_mirep allocator

  @param  vm	Pointer of VM.
  @return	Pointer of allocated mrb_mirep
*/
mrb_mirep *mrbc_irep_alloc(struct VM *vm)
{
  mrb_mirep *p = (mrb_mirep *)mrbc_alloc(vm, sizeof(mrb_mirep));
  if( p )
    memset(p, 0, sizeof(mrb_mirep));	// caution: assume NULL is zero.
  return p;
}


//================================================================
/*!@brief
  release mrb_mirep holds memory
*/
void mrbc_irep_free(mrb_mirep *irep)
{
  //do nothing
}


//================================================================
/*! mrb_instance constructor

  @param  vm    Pointer to VM.
  @param  cls	Pointer to Class (mrb_class).
  @param  size	size of additional data.
  @return       mrb_instance object.
*/
mrb_value mrbc_instance_new(struct VM *vm, mrb_class *cls, int size)
{
  mrb_value v = {.tt = MRB_TT_OBJECT};
  v.instance = (mrb_instance *)mrbc_alloc(vm, sizeof(mrb_instance) + size);
  if( v.instance == NULL ) return v;	// ENOMEM

  //TODO
#if 0
  v.instance->ivar = mrbc_kv_new(vm, 0);
  if( v.instance->ivar == NULL ) {	// ENOMEM
    mrbc_raw_free(v.instance);
    v.instance = NULL;
    return v;
  }
#endif
  
  v.instance->ref_count = 1;
  v.instance->tt = MRB_TT_OBJECT;	// for debug only.
  v.instance->cls = cls;

  return v;
}



//================================================================
/*! mrb_instance destructor

  @param  v	pointer to target value
*/
void mrbc_instance_delete(mrb_value *v)
{
  //TODO
#if 0
  mrbc_kv_delete( v->instance->ivar );
#endif
  mrbc_raw_free( v->instance );
}


//================================================================
/*! instance variable setter

  @param  obj		pointer to target.
  @param  sym_id	key symbol ID.
  @param  v		pointer to value.
*/
void mrbc_instance_setiv(mrb_object *obj, mrb_sym sym_id, mrb_value *v)
{
  //TODO
#if 0
  mrbc_dup(v);
  mrbc_kv_set( obj->instance->ivar, sym_id, v );
#endif
}


//================================================================
/*! instance variable getter

  @param  obj		pointer to target.
  @param  sym_id	key symbol ID.
  @return		value.
*/
mrb_value mrbc_instance_getiv(mrb_object *obj, mrb_sym sym_id)
{
  //TODO
#if 0
  mrb_value *v = mrbc_kv_get( obj->instance->ivar, sym_id );
  if( !v ) return mrb_nil_value();

  mrbc_dup(v);
  return *v;
#else
  mrb_value v;
  return v;
#endif
}
