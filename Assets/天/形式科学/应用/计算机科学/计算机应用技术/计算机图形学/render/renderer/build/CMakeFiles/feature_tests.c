
  const char features[] = {"\n"
"C_FEATURE:"
<<<<<<< HEAD
#if (__GNUC__ * 100 + __GNUC_MINOR__) >= 304
=======
#if (__GNUC__ * 100 + __GNUC_MINOR__) >= 404
>>>>>>> fc8ba0cf7be3fa4968aa789ce1ea12620fbd209d
"1"
#else
"0"
#endif
"c_function_prototypes\n"
"C_FEATURE:"
<<<<<<< HEAD
#if (__GNUC__ * 100 + __GNUC_MINOR__) >= 304 && defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
=======
#if (__GNUC__ * 100 + __GNUC_MINOR__) >= 404 && defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
>>>>>>> fc8ba0cf7be3fa4968aa789ce1ea12620fbd209d
"1"
#else
"0"
#endif
"c_restrict\n"
"C_FEATURE:"
#if (__GNUC__ * 100 + __GNUC_MINOR__) >= 406 && defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201000L
"1"
#else
"0"
#endif
"c_static_assert\n"
"C_FEATURE:"
<<<<<<< HEAD
#if (__GNUC__ * 100 + __GNUC_MINOR__) >= 304 && defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
=======
#if (__GNUC__ * 100 + __GNUC_MINOR__) >= 404 && defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
>>>>>>> fc8ba0cf7be3fa4968aa789ce1ea12620fbd209d
"1"
#else
"0"
#endif
"c_variadic_macros\n"

};

int main(int argc, char** argv) { (void)argv; return features[argc]; }
