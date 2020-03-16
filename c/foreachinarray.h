#ifndef _FOR_EACH_IN_ARRAY_H_
#define _FOR_EACH_IN_ARRAY_H_

#define forEachInArray(fe_arrType, fe_arr, fe_fn_body)                                    \
{                                                                                         \
  int i=0;                                                                                \
  for(;i<sizeof(fe_arr)/sizeof(fe_arrType);i++) {  fe_arr[i] = fe_fn_body(&fe_arr[i]); }  \
}


#endif /* _FOR_EACH_IN_ARRAY_H_ */
