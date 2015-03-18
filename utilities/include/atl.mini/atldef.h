#pragma  once

#define HIMETRIC_PER_INCH   2540
#define MAP_PIX_TO_LOGHIM(x,ppli)   MulDiv(HIMETRIC_PER_INCH, (x), (ppli))
#define MAP_LOGHIM_TO_PIX(x,ppli)   MulDiv((ppli), (x), HIMETRIC_PER_INCH)

#ifndef ATLTRACENOTIMPL
#define ATLENSURE_THROW(a,b)
#endif

#ifndef ATLTRACENOTIMPL
#define ATLTRACENOTIMPL(funcname)   return E_NOTIMPL
#endif

#ifndef ATLASSERT
#define ATLASSERT SASSERT
#endif // ATLASSERT

#ifndef ATLASSUME
#define ATLASSUME(expr) do { ATLASSERT(expr); __analysis_assume(!!(expr)); } while(0)
#endif // ATLASSUME

#ifndef ATL_NO_VTABLE
#define ATL_NO_VTABLE    __declspec(novtable)
#endif

#ifndef ATL_DEPRECATED
#define ATL_DEPRECATED(x);
#endif

#ifndef ATLENSURE
#define ATLENSURE(x);
#endif

/* Used inside COM methods that do not want to throw */
#ifndef ATLENSURE_RETURN_VAL
#define ATLENSURE_RETURN_VAL(expr, val)        \
    do {                                           \
    int __atl_condVal=!!(expr);                \
    ATLASSERT(__atl_condVal);                  \
    if(!(__atl_condVal)) return val;           \
    } while (0) 
#endif // ATLENSURE_RETURN_VAL

#ifndef ATLTRACE
#define ATLTRACE STRACE
#endif