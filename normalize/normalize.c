#include "m_pd.h"

static t_class *normalize_class;

typedef struct _normalize{
  t_object x_obj;
  t_float out_val;
  t_outlet *f_out;
} t_normalize;

void normalize_applymath(t_normalize *x, t_float in_val)
{
  x->out_val = 2*in_val-1;
  outlet_float(x->f_out, x->out_val);
}

void *normalize_new(void)
{
  t_normalize *x = (t_normalize *)pd_new(normalize_class);

  x->f_out = outlet_new(&x->x_obj, &s_float);

  return (void *)x;
}


void normalize_setup(void)
{
  normalize_class = class_new(gensym("normalize"),
        (t_newmethod)normalize_new, 0, sizeof(t_normalize),
        CLASS_DEFAULT, 0);

  class_addmethod(normalize_class,
        (t_method)normalize_applymath, &s_float, A_FLOAT, 0);
}
