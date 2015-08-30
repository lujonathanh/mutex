/* File: permute_matrixmodule.c
 * This file is auto-generated with f2py (version:2).
 * f2py is a Fortran to Python Interface Generator (FPIG), Second Edition,
 * written by Pearu Peterson <pearu@cens.ioc.ee>.
 * See http://cens.ioc.ee/projects/f2py2e/
 * Generation date: Sat May 30 15:26:59 2015
 * $Revision:$
 * $Date:$
 * Do not edit this file directly unless you know what you are doing!!!
 */
#ifdef __cplusplus
extern "C" {
#endif

/*********************** See f2py2e/cfuncs.py: includes ***********************/
#include "Python.h"
#include <stdarg.h>
#include "fortranobject.h"
#include <math.h>

/**************** See f2py2e/rules.py: mod_rules['modulebody'] ****************/
static PyObject *permute_matrix_error;
static PyObject *permute_matrix_module;

/*********************** See f2py2e/cfuncs.py: typedefs ***********************/
/*need_typedefs*/

/****************** See f2py2e/cfuncs.py: typedefs_generated ******************/
/*need_typedefs_generated*/

/********************** See f2py2e/cfuncs.py: cppmacros **********************/
#if defined(PREPEND_FORTRAN)
#if defined(NO_APPEND_FORTRAN)
#if defined(UPPERCASE_FORTRAN)
#define F_WRAPPEDFUNC(f,F) _F2PYWRAP##F
#else
#define F_WRAPPEDFUNC(f,F) _f2pywrap##f
#endif
#else
#if defined(UPPERCASE_FORTRAN)
#define F_WRAPPEDFUNC(f,F) _F2PYWRAP##F##_
#else
#define F_WRAPPEDFUNC(f,F) _f2pywrap##f##_
#endif
#endif
#else
#if defined(NO_APPEND_FORTRAN)
#if defined(UPPERCASE_FORTRAN)
#define F_WRAPPEDFUNC(f,F) F2PYWRAP##F
#else
#define F_WRAPPEDFUNC(f,F) f2pywrap##f
#endif
#else
#if defined(UPPERCASE_FORTRAN)
#define F_WRAPPEDFUNC(f,F) F2PYWRAP##F##_
#else
#define F_WRAPPEDFUNC(f,F) f2pywrap##f##_
#endif
#endif
#endif
#if defined(UNDERSCORE_G77)
#define F_WRAPPEDFUNC_US(f,F) F_WRAPPEDFUNC(f##_,F##_)
#else
#define F_WRAPPEDFUNC_US(f,F) F_WRAPPEDFUNC(f,F)
#endif

#if defined(PREPEND_FORTRAN)
#if defined(NO_APPEND_FORTRAN)
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) _##F
#else
#define F_FUNC(f,F) _##f
#endif
#else
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) _##F##_
#else
#define F_FUNC(f,F) _##f##_
#endif
#endif
#else
#if defined(NO_APPEND_FORTRAN)
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) F
#else
#define F_FUNC(f,F) f
#endif
#else
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) F##_
#else
#define F_FUNC(f,F) f##_
#endif
#endif
#endif
#if defined(UNDERSCORE_G77)
#define F_FUNC_US(f,F) F_FUNC(f##_,F##_)
#else
#define F_FUNC_US(f,F) F_FUNC(f,F)
#endif

#define rank(var) var ## _Rank
#define shape(var,dim) var ## _Dims[dim]
#define old_rank(var) (((PyArrayObject *)(capi_ ## var ## _tmp))->nd)
#define old_shape(var,dim) (((PyArrayObject *)(capi_ ## var ## _tmp))->dimensions[dim])
#define fshape(var,dim) shape(var,rank(var)-dim-1)
#define len(var) shape(var,0)
#define flen(var) fshape(var,0)
#define old_size(var) PyArray_SIZE((PyArrayObject *)(capi_ ## var ## _tmp))
/* #define index(i) capi_i ## i */
#define slen(var) capi_ ## var ## _len
#define size(var, ...) f2py_size((PyArrayObject *)(capi_ ## var ## _tmp), ## __VA_ARGS__, -1)

#define CHECKSCALAR(check,tcheck,name,show,var)\
  if (!(check)) {\
    char errstring[256];\
    sprintf(errstring, "%s: "show, "("tcheck") failed for "name, var);\
    PyErr_SetString(permute_matrix_error,errstring);\
    /*goto capi_fail;*/\
  } else 
#ifdef DEBUGCFUNCS
#define CFUNCSMESS(mess) fprintf(stderr,"debug-capi:"mess);
#define CFUNCSMESSPY(mess,obj) CFUNCSMESS(mess) \
  PyObject_Print((PyObject *)obj,stderr,Py_PRINT_RAW);\
  fprintf(stderr,"\n");
#else
#define CFUNCSMESS(mess)
#define CFUNCSMESSPY(mess,obj)
#endif

#ifndef max
#define max(a,b) ((a > b) ? (a) : (b))
#endif
#ifndef min
#define min(a,b) ((a < b) ? (a) : (b))
#endif
#ifndef MAX
#define MAX(a,b) ((a > b) ? (a) : (b))
#endif
#ifndef MIN
#define MIN(a,b) ((a < b) ? (a) : (b))
#endif


/************************ See f2py2e/cfuncs.py: cfuncs ************************/
static int f2py_size(PyArrayObject* var, ...)
{
  npy_int sz = 0;
  npy_int dim;
  npy_int rank;
  va_list argp;
  va_start(argp, var);
  dim = va_arg(argp, npy_int);
  if (dim==-1)
    {
      sz = PyArray_SIZE(var);
    }
  else
    {
      rank = PyArray_NDIM(var);
      if (dim>=1 && dim<=rank)
        sz = PyArray_DIM(var, dim-1);
      else
        fprintf(stderr, "f2py_size: 2nd argument value=%d fails to satisfy 1<=value<=%d. Result will be 0.\n", dim, rank);
    }
  va_end(argp);
  return sz;
}

static int int_from_pyobj(int* v,PyObject *obj,const char *errmess) {
  PyObject* tmp = NULL;
  if (PyInt_Check(obj)) {
    *v = (int)PyInt_AS_LONG(obj);
    return 1;
  }
  tmp = PyNumber_Int(obj);
  if (tmp) {
    *v = PyInt_AS_LONG(tmp);
    Py_DECREF(tmp);
    return 1;
  }
  if (PyComplex_Check(obj))
    tmp = PyObject_GetAttrString(obj,"real");
  else if (PyString_Check(obj) || PyUnicode_Check(obj))
    /*pass*/;
  else if (PySequence_Check(obj))
    tmp = PySequence_GetItem(obj,0);
  if (tmp) {
    PyErr_Clear();
    if (int_from_pyobj(v,tmp,errmess)) {Py_DECREF(tmp); return 1;}
    Py_DECREF(tmp);
  }
  {
    PyObject* err = PyErr_Occurred();
    if (err==NULL) err = permute_matrix_error;
    PyErr_SetString(err,errmess);
  }
  return 0;
}

static int double_from_pyobj(double* v,PyObject *obj,const char *errmess) {
  PyObject* tmp = NULL;
  if (PyFloat_Check(obj)) {
#ifdef __sgi
    *v = PyFloat_AsDouble(obj);
#else
    *v = PyFloat_AS_DOUBLE(obj);
#endif
    return 1;
  }
  tmp = PyNumber_Float(obj);
  if (tmp) {
#ifdef __sgi
    *v = PyFloat_AsDouble(tmp);
#else
    *v = PyFloat_AS_DOUBLE(tmp);
#endif
    Py_DECREF(tmp);
    return 1;
  }
  if (PyComplex_Check(obj))
    tmp = PyObject_GetAttrString(obj,"real");
  else if (PyString_Check(obj) || PyUnicode_Check(obj))
    /*pass*/;
  else if (PySequence_Check(obj))
    tmp = PySequence_GetItem(obj,0);
  if (tmp) {
    PyErr_Clear();
    if (double_from_pyobj(v,tmp,errmess)) {Py_DECREF(tmp); return 1;}
    Py_DECREF(tmp);
  }
  {
    PyObject* err = PyErr_Occurred();
    if (err==NULL) err = permute_matrix_error;
    PyErr_SetString(err,errmess);
  }
  return 0;
}


/********************* See f2py2e/cfuncs.py: userincludes *********************/
/*need_userincludes*/

/********************* See f2py2e/capi_rules.py: usercode *********************/


/* See f2py2e/rules.py */
extern void F_WRAPPEDFUNC_US(nth_one,NTH_ONE)(int*,int*,int*,int*,int*,int*,int*);
extern void F_FUNC_US(seed_prng,SEED_PRNG)(int*);
extern void F_WRAPPEDFUNC(choice,CHOICE)(int*,double*,int*,double*);
extern void F_FUNC(cdf,CDF)(double*,int*,int*);
extern void F_FUNC_US(bipartite_edge_swap,BIPARTITE_EDGE_SWAP)(int*,int*,int*,int*,int*,int*,int*,int*,int*);
/*eof externroutines*/

/******************** See f2py2e/capi_rules.py: usercode1 ********************/


/******************* See f2py2e/cb_rules.py: buildcallback *******************/
/*need_callbacks*/

/*********************** See f2py2e/rules.py: buildapi ***********************/

/********************************** nth_one **********************************/
static char doc_f2py_rout_permute_matrix_nth_one[] = "\
nth_one = nth_one(arr,index_bn,t,num,[m,n])\n\nWrapper for ``nth_one``.\
\n\nParameters\n----------\n"
"arr : input rank-2 array('i') with bounds (m,n)\n"
"index_bn : input int\n"
"t : input int\n"
"num : input int\n"
"\nOther Parameters\n----------------\n"
"m : input int, optional\n    Default: shape(arr,0)\n"
"n : input int, optional\n    Default: shape(arr,1)\n"
"\nReturns\n-------\n"
"nth_one : int";
/* extern void F_WRAPPEDFUNC_US(nth_one,NTH_ONE)(int*,int*,int*,int*,int*,int*,int*); */
static PyObject *f2py_rout_permute_matrix_nth_one(const PyObject *capi_self,
                           PyObject *capi_args,
                           PyObject *capi_keywds,
                           void (*f2py_func)(int*,int*,int*,int*,int*,int*,int*)) {
  PyObject * volatile capi_buildvalue = NULL;
  volatile int f2py_success = 1;
/*decl*/

  int nth_one = 0;
  int *arr = NULL;
  npy_intp arr_Dims[2] = {-1, -1};
  const int arr_Rank = 2;
  PyArrayObject *capi_arr_tmp = NULL;
  int capi_arr_intent = 0;
  PyObject *arr_capi = Py_None;
  int index_bn = 0;
  PyObject *index_bn_capi = Py_None;
  int t = 0;
  PyObject *t_capi = Py_None;
  int num = 0;
  PyObject *num_capi = Py_None;
  int m = 0;
  PyObject *m_capi = Py_None;
  int n = 0;
  PyObject *n_capi = Py_None;
  static char *capi_kwlist[] = {"arr","index_bn","t","num","m","n",NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_clock();
#endif
  if (!PyArg_ParseTupleAndKeywords(capi_args,capi_keywds,\
    "OOOO|OO:permute_matrix.nth_one",\
    capi_kwlist,&arr_capi,&index_bn_capi,&t_capi,&num_capi,&m_capi,&n_capi))
    return NULL;
/*frompyobj*/
  /* Processing variable arr */
  ;
  capi_arr_intent |= F2PY_INTENT_IN;
  capi_arr_tmp = array_from_pyobj(NPY_INT,arr_Dims,arr_Rank,capi_arr_intent,arr_capi);
  if (capi_arr_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(permute_matrix_error,"failed in converting 1st argument `arr' of permute_matrix.nth_one to C/Fortran array" );
  } else {
    arr = (int *)(capi_arr_tmp->data);

  /* Processing variable num */
    f2py_success = int_from_pyobj(&num,num_capi,"permute_matrix.nth_one() 4th argument (num) can't be converted to int");
  if (f2py_success) {
  /* Processing variable nth_one */
  /* Processing variable t */
    f2py_success = int_from_pyobj(&t,t_capi,"permute_matrix.nth_one() 3rd argument (t) can't be converted to int");
  if (f2py_success) {
  /* Processing variable index_bn */
    f2py_success = int_from_pyobj(&index_bn,index_bn_capi,"permute_matrix.nth_one() 2nd argument (index_bn) can't be converted to int");
  if (f2py_success) {
  /* Processing variable m */
  if (m_capi == Py_None) m = shape(arr,0); else
    f2py_success = int_from_pyobj(&m,m_capi,"permute_matrix.nth_one() 1st keyword (m) can't be converted to int");
  if (f2py_success) {
  CHECKSCALAR(shape(arr,0)==m,"shape(arr,0)==m","1st keyword m","nth_one:m=%d",m) {
  /* Processing variable n */
  if (n_capi == Py_None) n = shape(arr,1); else
    f2py_success = int_from_pyobj(&n,n_capi,"permute_matrix.nth_one() 2nd keyword (n) can't be converted to int");
  if (f2py_success) {
  CHECKSCALAR(shape(arr,1)==n,"shape(arr,1)==n","2nd keyword n","nth_one:n=%d",n) {
/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_call_clock();
#endif
/*callfortranroutine*/
  (*f2py_func)(&nth_one,arr,&index_bn,&t,&num,&m,&n);
if (PyErr_Occurred())
  f2py_success = 0;
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_call_clock();
#endif
/*end of callfortranroutine*/
    if (f2py_success) {
/*pyobjfrom*/
/*end of pyobjfrom*/
    CFUNCSMESS("Building return value.\n");
    capi_buildvalue = Py_BuildValue("i",nth_one);
/*closepyobjfrom*/
/*end of closepyobjfrom*/
    } /*if (f2py_success) after callfortranroutine*/
/*cleanupfrompyobj*/
  } /*CHECKSCALAR(shape(arr,1)==n)*/
  } /*if (f2py_success) of n*/
  /* End of cleaning variable n */
  } /*CHECKSCALAR(shape(arr,0)==m)*/
  } /*if (f2py_success) of m*/
  /* End of cleaning variable m */
  } /*if (f2py_success) of index_bn*/
  /* End of cleaning variable index_bn */
  } /*if (f2py_success) of t*/
  /* End of cleaning variable t */
  /* End of cleaning variable nth_one */
  } /*if (f2py_success) of num*/
  /* End of cleaning variable num */
  if((PyObject *)capi_arr_tmp!=arr_capi) {
    Py_XDECREF(capi_arr_tmp); }
  }  /*if (capi_arr_tmp == NULL) ... else of arr*/
  /* End of cleaning variable arr */
/*end of cleanupfrompyobj*/
  if (capi_buildvalue == NULL) {
/*routdebugfailure*/
  } else {
/*routdebugleave*/
  }
  CFUNCSMESS("Freeing memory.\n");
/*freemem*/
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_clock();
#endif
  return capi_buildvalue;
}
/******************************* end of nth_one *******************************/

/********************************* seed_prng *********************************/
static char doc_f2py_rout_permute_matrix_seed_prng[] = "\
seed_prng(n)\n\nWrapper for ``seed_prng``.\
\n\nParameters\n----------\n"
"n : input int";
/* extern void F_FUNC_US(seed_prng,SEED_PRNG)(int*); */
static PyObject *f2py_rout_permute_matrix_seed_prng(const PyObject *capi_self,
                           PyObject *capi_args,
                           PyObject *capi_keywds,
                           void (*f2py_func)(int*)) {
  PyObject * volatile capi_buildvalue = NULL;
  volatile int f2py_success = 1;
/*decl*/

  int n = 0;
  PyObject *n_capi = Py_None;
  static char *capi_kwlist[] = {"n",NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_clock();
#endif
  if (!PyArg_ParseTupleAndKeywords(capi_args,capi_keywds,\
    "O:permute_matrix.seed_prng",\
    capi_kwlist,&n_capi))
    return NULL;
/*frompyobj*/
  /* Processing variable n */
    f2py_success = int_from_pyobj(&n,n_capi,"permute_matrix.seed_prng() 1st argument (n) can't be converted to int");
  if (f2py_success) {
/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_call_clock();
#endif
/*callfortranroutine*/
        (*f2py_func)(&n);
if (PyErr_Occurred())
  f2py_success = 0;
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_call_clock();
#endif
/*end of callfortranroutine*/
    if (f2py_success) {
/*pyobjfrom*/
/*end of pyobjfrom*/
    CFUNCSMESS("Building return value.\n");
    capi_buildvalue = Py_BuildValue("");
/*closepyobjfrom*/
/*end of closepyobjfrom*/
    } /*if (f2py_success) after callfortranroutine*/
/*cleanupfrompyobj*/
  } /*if (f2py_success) of n*/
  /* End of cleaning variable n */
/*end of cleanupfrompyobj*/
  if (capi_buildvalue == NULL) {
/*routdebugfailure*/
  } else {
/*routdebugleave*/
  }
  CFUNCSMESS("Freeing memory.\n");
/*freemem*/
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_clock();
#endif
  return capi_buildvalue;
}
/****************************** end of seed_prng ******************************/

/*********************************** choice ***********************************/
static char doc_f2py_rout_permute_matrix_choice[] = "\
choice = choice(dist,p,[n])\n\nWrapper for ``choice``.\
\n\nParameters\n----------\n"
"dist : input rank-1 array('d') with bounds (n)\n"
"p : input float\n"
"\nOther Parameters\n----------------\n"
"n : input int, optional\n    Default: len(dist)\n"
"\nReturns\n-------\n"
"choice : int";
/* extern void F_WRAPPEDFUNC(choice,CHOICE)(int*,double*,int*,double*); */
static PyObject *f2py_rout_permute_matrix_choice(const PyObject *capi_self,
                           PyObject *capi_args,
                           PyObject *capi_keywds,
                           void (*f2py_func)(int*,double*,int*,double*)) {
  PyObject * volatile capi_buildvalue = NULL;
  volatile int f2py_success = 1;
/*decl*/

  int choice = 0;
  double *dist = NULL;
  npy_intp dist_Dims[1] = {-1};
  const int dist_Rank = 1;
  PyArrayObject *capi_dist_tmp = NULL;
  int capi_dist_intent = 0;
  PyObject *dist_capi = Py_None;
  int n = 0;
  PyObject *n_capi = Py_None;
  double p = 0;
  PyObject *p_capi = Py_None;
  static char *capi_kwlist[] = {"dist","p","n",NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_clock();
#endif
  if (!PyArg_ParseTupleAndKeywords(capi_args,capi_keywds,\
    "OO|O:permute_matrix.choice",\
    capi_kwlist,&dist_capi,&p_capi,&n_capi))
    return NULL;
/*frompyobj*/
  /* Processing variable p */
    f2py_success = double_from_pyobj(&p,p_capi,"permute_matrix.choice() 2nd argument (p) can't be converted to double");
  if (f2py_success) {
  /* Processing variable dist */
  ;
  capi_dist_intent |= F2PY_INTENT_IN;
  capi_dist_tmp = array_from_pyobj(NPY_DOUBLE,dist_Dims,dist_Rank,capi_dist_intent,dist_capi);
  if (capi_dist_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(permute_matrix_error,"failed in converting 1st argument `dist' of permute_matrix.choice to C/Fortran array" );
  } else {
    dist = (double *)(capi_dist_tmp->data);

  /* Processing variable choice */
  /* Processing variable n */
  if (n_capi == Py_None) n = len(dist); else
    f2py_success = int_from_pyobj(&n,n_capi,"permute_matrix.choice() 1st keyword (n) can't be converted to int");
  if (f2py_success) {
  CHECKSCALAR(len(dist)>=n,"len(dist)>=n","1st keyword n","choice:n=%d",n) {
/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_call_clock();
#endif
/*callfortranroutine*/
  (*f2py_func)(&choice,dist,&n,&p);
if (PyErr_Occurred())
  f2py_success = 0;
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_call_clock();
#endif
/*end of callfortranroutine*/
    if (f2py_success) {
/*pyobjfrom*/
/*end of pyobjfrom*/
    CFUNCSMESS("Building return value.\n");
    capi_buildvalue = Py_BuildValue("i",choice);
/*closepyobjfrom*/
/*end of closepyobjfrom*/
    } /*if (f2py_success) after callfortranroutine*/
/*cleanupfrompyobj*/
  } /*CHECKSCALAR(len(dist)>=n)*/
  } /*if (f2py_success) of n*/
  /* End of cleaning variable n */
  /* End of cleaning variable choice */
  if((PyObject *)capi_dist_tmp!=dist_capi) {
    Py_XDECREF(capi_dist_tmp); }
  }  /*if (capi_dist_tmp == NULL) ... else of dist*/
  /* End of cleaning variable dist */
  } /*if (f2py_success) of p*/
  /* End of cleaning variable p */
/*end of cleanupfrompyobj*/
  if (capi_buildvalue == NULL) {
/*routdebugfailure*/
  } else {
/*routdebugleave*/
  }
  CFUNCSMESS("Freeing memory.\n");
/*freemem*/
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_clock();
#endif
  return capi_buildvalue;
}
/******************************* end of choice *******************************/

/************************************ cdf ************************************/
static char doc_f2py_rout_permute_matrix_cdf[] = "\
cdf(output,arr,[n])\n\nWrapper for ``cdf``.\
\n\nParameters\n----------\n"
"output : input rank-1 array('d') with bounds (n)\n"
"arr : input rank-1 array('i') with bounds (n)\n"
"\nOther Parameters\n----------------\n"
"n : input int, optional\n    Default: len(output)";
/* extern void F_FUNC(cdf,CDF)(double*,int*,int*); */
static PyObject *f2py_rout_permute_matrix_cdf(const PyObject *capi_self,
                           PyObject *capi_args,
                           PyObject *capi_keywds,
                           void (*f2py_func)(double*,int*,int*)) {
  PyObject * volatile capi_buildvalue = NULL;
  volatile int f2py_success = 1;
/*decl*/

  double *output = NULL;
  npy_intp output_Dims[1] = {-1};
  const int output_Rank = 1;
  PyArrayObject *capi_output_tmp = NULL;
  int capi_output_intent = 0;
  PyObject *output_capi = Py_None;
  int *arr = NULL;
  npy_intp arr_Dims[1] = {-1};
  const int arr_Rank = 1;
  PyArrayObject *capi_arr_tmp = NULL;
  int capi_arr_intent = 0;
  PyObject *arr_capi = Py_None;
  int n = 0;
  PyObject *n_capi = Py_None;
  static char *capi_kwlist[] = {"output","arr","n",NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_clock();
#endif
  if (!PyArg_ParseTupleAndKeywords(capi_args,capi_keywds,\
    "OO|O:permute_matrix.cdf",\
    capi_kwlist,&output_capi,&arr_capi,&n_capi))
    return NULL;
/*frompyobj*/
  /* Processing variable output */
  ;
  capi_output_intent |= F2PY_INTENT_IN;
  capi_output_tmp = array_from_pyobj(NPY_DOUBLE,output_Dims,output_Rank,capi_output_intent,output_capi);
  if (capi_output_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(permute_matrix_error,"failed in converting 1st argument `output' of permute_matrix.cdf to C/Fortran array" );
  } else {
    output = (double *)(capi_output_tmp->data);

  /* Processing variable n */
  if (n_capi == Py_None) n = len(output); else
    f2py_success = int_from_pyobj(&n,n_capi,"permute_matrix.cdf() 1st keyword (n) can't be converted to int");
  if (f2py_success) {
  CHECKSCALAR(len(output)>=n,"len(output)>=n","1st keyword n","cdf:n=%d",n) {
  /* Processing variable arr */
  arr_Dims[0]=n;
  capi_arr_intent |= F2PY_INTENT_IN;
  capi_arr_tmp = array_from_pyobj(NPY_INT,arr_Dims,arr_Rank,capi_arr_intent,arr_capi);
  if (capi_arr_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(permute_matrix_error,"failed in converting 2nd argument `arr' of permute_matrix.cdf to C/Fortran array" );
  } else {
    arr = (int *)(capi_arr_tmp->data);

/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_call_clock();
#endif
/*callfortranroutine*/
        (*f2py_func)(output,arr,&n);
if (PyErr_Occurred())
  f2py_success = 0;
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_call_clock();
#endif
/*end of callfortranroutine*/
    if (f2py_success) {
/*pyobjfrom*/
/*end of pyobjfrom*/
    CFUNCSMESS("Building return value.\n");
    capi_buildvalue = Py_BuildValue("");
/*closepyobjfrom*/
/*end of closepyobjfrom*/
    } /*if (f2py_success) after callfortranroutine*/
/*cleanupfrompyobj*/
  if((PyObject *)capi_arr_tmp!=arr_capi) {
    Py_XDECREF(capi_arr_tmp); }
  }  /*if (capi_arr_tmp == NULL) ... else of arr*/
  /* End of cleaning variable arr */
  } /*CHECKSCALAR(len(output)>=n)*/
  } /*if (f2py_success) of n*/
  /* End of cleaning variable n */
  if((PyObject *)capi_output_tmp!=output_capi) {
    Py_XDECREF(capi_output_tmp); }
  }  /*if (capi_output_tmp == NULL) ... else of output*/
  /* End of cleaning variable output */
/*end of cleanupfrompyobj*/
  if (capi_buildvalue == NULL) {
/*routdebugfailure*/
  } else {
/*routdebugleave*/
  }
  CFUNCSMESS("Freeing memory.\n");
/*freemem*/
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_clock();
#endif
  return capi_buildvalue;
}
/********************************* end of cdf *********************************/

/**************************** bipartite_edge_swap ****************************/
static char doc_f2py_rout_permute_matrix_bipartite_edge_swap[] = "\
b = bipartite_edge_swap(a,x_degrees,y_degrees,nswap,max_tries,seed,[m,n])\n\nWrapper for ``bipartite_edge_swap``.\
\n\nParameters\n----------\n"
"a : input rank-2 array('i') with bounds (m,n)\n"
"x_degrees : input rank-1 array('i') with bounds (m)\n"
"y_degrees : input rank-1 array('i') with bounds (n)\n"
"nswap : input int\n"
"max_tries : input int\n"
"seed : input int\n"
"\nOther Parameters\n----------------\n"
"m : input int, optional\n    Default: shape(a,0)\n"
"n : input int, optional\n    Default: shape(a,1)\n"
"\nReturns\n-------\n"
"b : rank-2 array('i') with bounds (m,n)";
/* extern void F_FUNC_US(bipartite_edge_swap,BIPARTITE_EDGE_SWAP)(int*,int*,int*,int*,int*,int*,int*,int*,int*); */
static PyObject *f2py_rout_permute_matrix_bipartite_edge_swap(const PyObject *capi_self,
                           PyObject *capi_args,
                           PyObject *capi_keywds,
                           void (*f2py_func)(int*,int*,int*,int*,int*,int*,int*,int*,int*)) {
  PyObject * volatile capi_buildvalue = NULL;
  volatile int f2py_success = 1;
/*decl*/

  int *b = NULL;
  npy_intp b_Dims[2] = {-1, -1};
  const int b_Rank = 2;
  PyArrayObject *capi_b_tmp = NULL;
  int capi_b_intent = 0;
  int *a = NULL;
  npy_intp a_Dims[2] = {-1, -1};
  const int a_Rank = 2;
  PyArrayObject *capi_a_tmp = NULL;
  int capi_a_intent = 0;
  PyObject *a_capi = Py_None;
  int *x_degrees = NULL;
  npy_intp x_degrees_Dims[1] = {-1};
  const int x_degrees_Rank = 1;
  PyArrayObject *capi_x_degrees_tmp = NULL;
  int capi_x_degrees_intent = 0;
  PyObject *x_degrees_capi = Py_None;
  int *y_degrees = NULL;
  npy_intp y_degrees_Dims[1] = {-1};
  const int y_degrees_Rank = 1;
  PyArrayObject *capi_y_degrees_tmp = NULL;
  int capi_y_degrees_intent = 0;
  PyObject *y_degrees_capi = Py_None;
  int nswap = 0;
  PyObject *nswap_capi = Py_None;
  int max_tries = 0;
  PyObject *max_tries_capi = Py_None;
  int seed = 0;
  PyObject *seed_capi = Py_None;
  int m = 0;
  PyObject *m_capi = Py_None;
  int n = 0;
  PyObject *n_capi = Py_None;
  static char *capi_kwlist[] = {"a","x_degrees","y_degrees","nswap","max_tries","seed","m","n",NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_clock();
#endif
  if (!PyArg_ParseTupleAndKeywords(capi_args,capi_keywds,\
    "OOOOOO|OO:permute_matrix.bipartite_edge_swap",\
    capi_kwlist,&a_capi,&x_degrees_capi,&y_degrees_capi,&nswap_capi,&max_tries_capi,&seed_capi,&m_capi,&n_capi))
    return NULL;
/*frompyobj*/
  /* Processing variable seed */
    f2py_success = int_from_pyobj(&seed,seed_capi,"permute_matrix.bipartite_edge_swap() 6th argument (seed) can't be converted to int");
  if (f2py_success) {
  /* Processing variable max_tries */
    f2py_success = int_from_pyobj(&max_tries,max_tries_capi,"permute_matrix.bipartite_edge_swap() 5th argument (max_tries) can't be converted to int");
  if (f2py_success) {
  /* Processing variable a */
  ;
  capi_a_intent |= F2PY_INTENT_IN;
  capi_a_tmp = array_from_pyobj(NPY_INT,a_Dims,a_Rank,capi_a_intent,a_capi);
  if (capi_a_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(permute_matrix_error,"failed in converting 1st argument `a' of permute_matrix.bipartite_edge_swap to C/Fortran array" );
  } else {
    a = (int *)(capi_a_tmp->data);

  /* Processing variable nswap */
    f2py_success = int_from_pyobj(&nswap,nswap_capi,"permute_matrix.bipartite_edge_swap() 4th argument (nswap) can't be converted to int");
  if (f2py_success) {
  /* Processing variable m */
  if (m_capi == Py_None) m = shape(a,0); else
    f2py_success = int_from_pyobj(&m,m_capi,"permute_matrix.bipartite_edge_swap() 1st keyword (m) can't be converted to int");
  if (f2py_success) {
  CHECKSCALAR(shape(a,0)==m,"shape(a,0)==m","1st keyword m","bipartite_edge_swap:m=%d",m) {
  /* Processing variable n */
  if (n_capi == Py_None) n = shape(a,1); else
    f2py_success = int_from_pyobj(&n,n_capi,"permute_matrix.bipartite_edge_swap() 2nd keyword (n) can't be converted to int");
  if (f2py_success) {
  CHECKSCALAR(shape(a,1)==n,"shape(a,1)==n","2nd keyword n","bipartite_edge_swap:n=%d",n) {
  /* Processing variable x_degrees */
  x_degrees_Dims[0]=m;
  capi_x_degrees_intent |= F2PY_INTENT_IN;
  capi_x_degrees_tmp = array_from_pyobj(NPY_INT,x_degrees_Dims,x_degrees_Rank,capi_x_degrees_intent,x_degrees_capi);
  if (capi_x_degrees_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(permute_matrix_error,"failed in converting 2nd argument `x_degrees' of permute_matrix.bipartite_edge_swap to C/Fortran array" );
  } else {
    x_degrees = (int *)(capi_x_degrees_tmp->data);

  /* Processing variable b */
  b_Dims[0]=m,b_Dims[1]=n;
  capi_b_intent |= F2PY_INTENT_OUT|F2PY_INTENT_HIDE;
  capi_b_tmp = array_from_pyobj(NPY_INT,b_Dims,b_Rank,capi_b_intent,Py_None);
  if (capi_b_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(permute_matrix_error,"failed in converting hidden `b' of permute_matrix.bipartite_edge_swap to C/Fortran array" );
  } else {
    b = (int *)(capi_b_tmp->data);

  /* Processing variable y_degrees */
  y_degrees_Dims[0]=n;
  capi_y_degrees_intent |= F2PY_INTENT_IN;
  capi_y_degrees_tmp = array_from_pyobj(NPY_INT,y_degrees_Dims,y_degrees_Rank,capi_y_degrees_intent,y_degrees_capi);
  if (capi_y_degrees_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(permute_matrix_error,"failed in converting 3rd argument `y_degrees' of permute_matrix.bipartite_edge_swap to C/Fortran array" );
  } else {
    y_degrees = (int *)(capi_y_degrees_tmp->data);

/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_call_clock();
#endif
/*callfortranroutine*/
        (*f2py_func)(b,a,x_degrees,y_degrees,&nswap,&max_tries,&seed,&m,&n);
if (PyErr_Occurred())
  f2py_success = 0;
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_call_clock();
#endif
/*end of callfortranroutine*/
    if (f2py_success) {
/*pyobjfrom*/
/*end of pyobjfrom*/
    CFUNCSMESS("Building return value.\n");
    capi_buildvalue = Py_BuildValue("N",capi_b_tmp);
/*closepyobjfrom*/
/*end of closepyobjfrom*/
    } /*if (f2py_success) after callfortranroutine*/
/*cleanupfrompyobj*/
  if((PyObject *)capi_y_degrees_tmp!=y_degrees_capi) {
    Py_XDECREF(capi_y_degrees_tmp); }
  }  /*if (capi_y_degrees_tmp == NULL) ... else of y_degrees*/
  /* End of cleaning variable y_degrees */
  }  /*if (capi_b_tmp == NULL) ... else of b*/
  /* End of cleaning variable b */
  if((PyObject *)capi_x_degrees_tmp!=x_degrees_capi) {
    Py_XDECREF(capi_x_degrees_tmp); }
  }  /*if (capi_x_degrees_tmp == NULL) ... else of x_degrees*/
  /* End of cleaning variable x_degrees */
  } /*CHECKSCALAR(shape(a,1)==n)*/
  } /*if (f2py_success) of n*/
  /* End of cleaning variable n */
  } /*CHECKSCALAR(shape(a,0)==m)*/
  } /*if (f2py_success) of m*/
  /* End of cleaning variable m */
  } /*if (f2py_success) of nswap*/
  /* End of cleaning variable nswap */
  if((PyObject *)capi_a_tmp!=a_capi) {
    Py_XDECREF(capi_a_tmp); }
  }  /*if (capi_a_tmp == NULL) ... else of a*/
  /* End of cleaning variable a */
  } /*if (f2py_success) of max_tries*/
  /* End of cleaning variable max_tries */
  } /*if (f2py_success) of seed*/
  /* End of cleaning variable seed */
/*end of cleanupfrompyobj*/
  if (capi_buildvalue == NULL) {
/*routdebugfailure*/
  } else {
/*routdebugleave*/
  }
  CFUNCSMESS("Freeing memory.\n");
/*freemem*/
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_clock();
#endif
  return capi_buildvalue;
}
/************************* end of bipartite_edge_swap *************************/
/*eof body*/

/******************* See f2py2e/f90mod_rules.py: buildhooks *******************/
/*need_f90modhooks*/

/************** See f2py2e/rules.py: module_rules['modulebody'] **************/

/******************* See f2py2e/common_rules.py: buildhooks *******************/

/*need_commonhooks*/

/**************************** See f2py2e/rules.py ****************************/

static FortranDataDef f2py_routine_defs[] = {
  {"nth_one",-1,{{-1}},0,(char *)F_WRAPPEDFUNC_US(nth_one,NTH_ONE),(f2py_init_func)f2py_rout_permute_matrix_nth_one,doc_f2py_rout_permute_matrix_nth_one},
  {"seed_prng",-1,{{-1}},0,(char *)F_FUNC_US(seed_prng,SEED_PRNG),(f2py_init_func)f2py_rout_permute_matrix_seed_prng,doc_f2py_rout_permute_matrix_seed_prng},
  {"choice",-1,{{-1}},0,(char *)F_WRAPPEDFUNC(choice,CHOICE),(f2py_init_func)f2py_rout_permute_matrix_choice,doc_f2py_rout_permute_matrix_choice},
  {"cdf",-1,{{-1}},0,(char *)F_FUNC(cdf,CDF),(f2py_init_func)f2py_rout_permute_matrix_cdf,doc_f2py_rout_permute_matrix_cdf},
  {"bipartite_edge_swap",-1,{{-1}},0,(char *)F_FUNC_US(bipartite_edge_swap,BIPARTITE_EDGE_SWAP),(f2py_init_func)f2py_rout_permute_matrix_bipartite_edge_swap,doc_f2py_rout_permute_matrix_bipartite_edge_swap},

/*eof routine_defs*/
  {NULL}
};

static PyMethodDef f2py_module_methods[] = {

  {NULL,NULL}
};

#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef moduledef = {
  PyModuleDef_HEAD_INIT,
  "permute_matrix",
  NULL,
  -1,
  f2py_module_methods,
  NULL,
  NULL,
  NULL,
  NULL
};
#endif

#if PY_VERSION_HEX >= 0x03000000
#define RETVAL m
PyMODINIT_FUNC PyInit_permute_matrix(void) {
#else
#define RETVAL
PyMODINIT_FUNC initpermute_matrix(void) {
#endif
  int i;
  PyObject *m,*d, *s;
#if PY_VERSION_HEX >= 0x03000000
  m = permute_matrix_module = PyModule_Create(&moduledef);
#else
  m = permute_matrix_module = Py_InitModule("permute_matrix", f2py_module_methods);
#endif
  Py_TYPE(&PyFortran_Type) = &PyType_Type;
  import_array();
  if (PyErr_Occurred())
    {PyErr_SetString(PyExc_ImportError, "can't initialize module permute_matrix (failed to import numpy)"); return RETVAL;}
  d = PyModule_GetDict(m);
  s = PyString_FromString("$Revision: $");
  PyDict_SetItemString(d, "__version__", s);
#if PY_VERSION_HEX >= 0x03000000
  s = PyUnicode_FromString(
#else
  s = PyString_FromString(
#endif
    "This module 'permute_matrix' is auto-generated with f2py (version:2).\nFunctions:\n"
"  nth_one = nth_one(arr,index_bn,t,num,m=shape(arr,0),n=shape(arr,1))\n"
"  seed_prng(n)\n"
"  choice = choice(dist,p,n=len(dist))\n"
"  cdf(output,arr,n=len(output))\n"
"  b = bipartite_edge_swap(a,x_degrees,y_degrees,nswap,max_tries,seed,m=shape(a,0),n=shape(a,1))\n"
".");
  PyDict_SetItemString(d, "__doc__", s);
  permute_matrix_error = PyErr_NewException ("permute_matrix.error", NULL, NULL);
  Py_DECREF(s);
  for(i=0;f2py_routine_defs[i].name!=NULL;i++)
    PyDict_SetItemString(d, f2py_routine_defs[i].name,PyFortranObject_NewAsAttr(&f2py_routine_defs[i]));

    {
      extern int F_FUNC_US(nth_one,NTH_ONE)(void);
      PyObject* o = PyDict_GetItemString(d,"nth_one");
      PyObject_SetAttrString(o,"_cpointer", F2PyCapsule_FromVoidPtr((void*)F_FUNC_US(nth_one,NTH_ONE),NULL));
#if PY_VERSION_HEX >= 0x03000000
      PyObject_SetAttrString(o,"__name__", PyUnicode_FromString("nth_one"));
#else
      PyObject_SetAttrString(o,"__name__", PyString_FromString("nth_one"));
#endif
    }
    


    {
      extern int F_FUNC(choice,CHOICE)(void);
      PyObject* o = PyDict_GetItemString(d,"choice");
      PyObject_SetAttrString(o,"_cpointer", F2PyCapsule_FromVoidPtr((void*)F_FUNC(choice,CHOICE),NULL));
#if PY_VERSION_HEX >= 0x03000000
      PyObject_SetAttrString(o,"__name__", PyUnicode_FromString("choice"));
#else
      PyObject_SetAttrString(o,"__name__", PyString_FromString("choice"));
#endif
    }
    


/*eof initf2pywraphooks*/
/*eof initf90modhooks*/

/*eof initcommonhooks*/


#ifdef F2PY_REPORT_ATEXIT
  if (! PyErr_Occurred())
    on_exit(f2py_report_on_exit,(void*)"permute_matrix");
#endif

  return RETVAL;
}
#ifdef __cplusplus
}
#endif
