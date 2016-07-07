// PRINTF COLORS

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"
#define BL_RED "\x1B[1;31m"

// MACRO

#define RUN(x) printf(CYN "[RUN]" RESET " %s \n", x)
#define ASSERT_BLOCK(x) printf(MAG " [ASSERT BLOCK]" RESET " %s \n", x)
#define SUCCESS printf(GRN "  Assert Succcess ! " RESET "\n")
#define FAIL(T1, OP, T2) printf (BL_RED "  Assert Fail !" RESET RED " %s %s %s" RESET "\n",T1, OP, T2)
#define FAIL_INT(T1, OP, T2) printf (BL_RED "  Assert Fail !" RESET RED " %d %s %d" RESET "\n",T1, OP, T2)

// HEADER

void assert_str_eq(char *T1, char *T2);
void assert_str_not_eq(char *T1, char *T2);
void assert_int_eq(int T1, int T2);
void assert_int_not_eq(int T1, int T2);
void assert_eq(int result);
