#include <check.h>
#include <math.h>

#include "../Services/CalculatorCore/core.h"

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

START_TEST(random_test_1) {
  double math = 84;
  char infix[255] = "(256/32)/4*2+256/(32/4*2)+256/(32/4)*2";

  int status = 0;
  double s21_math = calculateExpression(infix, &status, 0);

  ck_assert_double_eq_tol(math, s21_math, 0.000001);
}
END_TEST

START_TEST(random_test_2) {
  double math = 734;
  char infix[255] = "2^3+22*33";

  int status = 0;
  double s21_math = calculateExpression(infix, &status, 0);

  ck_assert_double_eq_tol(math, s21_math, 0.000001);
}
END_TEST

START_TEST(random_test_3) {
  double math = 84;
  char infix[255] = "(256/32)/4*2+256/(32/4*2)+256/(32/4)*2";

  int status = 0;
  double s21_math = calculateExpression(infix, &status, 0);

  ck_assert_double_eq_tol(math, s21_math, 0.000001);
}
END_TEST

START_TEST(random_test_4) {
  double math = 84;
  char infix[255] = "(256/32)/4*2+256/(32/4*2)+256/(32/4)*2";

  int status = 0;
  double s21_math = calculateExpression(infix, &status, 0);

  ck_assert_double_eq_tol(math, s21_math, 0.000001);
}
END_TEST

START_TEST(random_test_5) {
  double math = 84;
  char infix[255] = "(256/32)/4*2+256/(32/4*2)+256/(32/4)*2";

  int status = 0;
  double s21_math = calculateExpression(infix, &status, 0);

  ck_assert_double_eq_tol(math, s21_math, 0.000001);
}
END_TEST

START_TEST(random_test_6) {
  double math = 3.688367;
  char infix[255] = "4^(acos(2/4))/tan(2*2)";
  int status = 0;
  double s21_math = calculateExpression(infix, &status, 0);

  ck_assert_double_eq_tol(s21_math, math, 0.00001);
}
END_TEST

START_TEST(test0) {
  double math = 1.570796;
  char infix[255] = "asin(1)";

  int status = 0;
  double s21_math = calculateExpression(infix, &status, 0);

  ck_assert_double_eq_tol(math, s21_math, 0.000001);
}
END_TEST

START_TEST(test1) {
  double math = 2.90464508432201;
  char infix[255] = "ln(10)+log(2)*sqrt(4)";

  int status = 0;
  double s21_math = calculateExpression(infix, &status, 0);

  ck_assert_double_eq_tol(math, s21_math, 0.000001);
}
END_TEST

START_TEST(test2) {
  double math = 0.125;
  char infix[255] = "1/2^3";

  int status = 0;
  double s21_math = calculateExpression(infix, &status, 0);

  ck_assert_double_eq_tol(math, s21_math, 0.000001);
}
END_TEST

START_TEST(test3) {
  double math = 4;
  char infix[255] = "(2+2)%(3+3)";

  int status = 0;
  double s21_math = calculateExpression(infix, &status, 0);

  ck_assert_double_eq_tol(math, s21_math, 0.000001);
}
END_TEST

START_TEST(test4) {
  double math = 210;
  char infix[255] = "10-20*(-10)";

  int status = 0;
  double s21_math = calculateExpression(infix, &status, 0);

  ck_assert_double_eq_tol(math, s21_math, 0.000001);
}
END_TEST

START_TEST(test5) {
  double math = 2.90464508432201;
  char infix[255] = "ln(10)+log(2)*sqrt(4)";

  int status = 0;
  double s21_math = calculateExpression(infix, &status, 0);

  ck_assert_double_eq_tol(math, s21_math, 0.000001);
}
END_TEST

START_TEST(test6) {
  double math = 123.456;
  char infix[255] = "123+0.456";

  int status = 0;
  double s21_math = calculateExpression(infix, &status, 0);

  ck_assert_double_eq_tol(math, s21_math, 0.000001);
}
END_TEST

START_TEST(test7) {
  double math = 246.648;
  char infix[255] =
      "5*(1.75+0.234)*sin(cos(tan(5%3))*tan(sin(5))+ln(2))*5^2+sin(5)";

  int status = 0;
  double s21_math = calculateExpression(infix, &status, 0);

  ck_assert_double_eq_tol(math, s21_math, 0.0001);
}
END_TEST

START_TEST(test8) {
  double math = -43.7456440;
  char infix[255] =
      "-5*(1.75+0.234)*-sin(cos(tan(5%3))*tan(sin(-5))+ln(2))*5^2+-sin(5)-13";

  int status = 0;
  double s21_math = calculateExpression(infix, &status, 0);

  ck_assert_double_eq_tol(math, s21_math, 0.000001);
}
END_TEST

START_TEST(test9) {
  double math = 0;
  char infix[255] = "1000%10%12";

  int status = 0;
  double s21_math = calculateExpression(infix, &status, 0);

  ck_assert_double_eq_tol(math, s21_math, 0.000001);
}
END_TEST

START_TEST(test10) {
  double math = 4354350;
  char infix[255] = "435435*10%232^3";

  int status = 0;
  double s21_math = calculateExpression(infix, &status, 0);

  ck_assert_double_eq_tol(math, s21_math, 0.000001);
}
END_TEST

START_TEST(test11) {
  double math = 2.4178516392292583e+24;
  char infix[255] = "2^(3^4)";

  int status = 0;
  double s21_math = calculateExpression(infix, &status, 0);

  ck_assert_double_eq_tol(math, s21_math, 0.000001);
}
END_TEST

START_TEST(test12) {
  double math = 16.601;
  char infix[255] = "2^(3^(4/3.14))";

  int status = 0;
  double s21_math = calculateExpression(infix, &status, 0);

  ck_assert_double_eq_tol(math, s21_math, 0.0001);
}
END_TEST

START_TEST(test13) {
  double math = -0.789992;
  char infix[255] = "sin(cos(-tan(5%3)-100))";

  int status = 0;
  double s21_math = calculateExpression(infix, &status, 0);

  ck_assert_double_eq_tol(math, s21_math, 0.000001);
}
END_TEST

START_TEST(test14) {
  double math = 0.009980;
  char infix[255] = "sin(sin(sin(sin(435435*10%232^3)+7)*3)+25)";

  int status = 0;
  double s21_math = calculateExpression(infix, &status, 0);

  ck_assert_double_eq_tol(math, s21_math, 0.000001);
}
END_TEST

START_TEST(test15) {
  double math = -3990.07216495;
  char infix[255] = "15/(7-(1+1))*3-(2+(1+1))*15/(7-(200+1))*3-(2+(1+1))*(15/"
                    "(7-(1+1))*3-(2+(1+1))+15/(7-(1+1))*3-(2+(1+1)))^3";

  int status = 0;
  double s21_math = calculateExpression(infix, &status, 0);

  ck_assert_double_eq_tol(math, s21_math, 0.000001);
}
END_TEST

START_TEST(test16) {
  double math = 56;
  char infix[255] =
      "-1-1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+"
      "1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1";

  int status = 0;
  double s21_math = calculateExpression(infix, &status, 0);

  ck_assert_double_eq_tol(math, s21_math, 0.000001);
}
END_TEST

START_TEST(test17) {
  double math = 6.10663961157;
  char infix[255] =
      "log(60)-ln(68+(36/2))/6^(96/45*2)-cos(sin(cos(tan(30))))+5";

  int status = 0;
  double s21_math = calculateExpression(infix, &status, 0);

  ck_assert_double_eq_tol(math, s21_math, 0.000001);
}
END_TEST

START_TEST(test18) {
  double math = -13.7229;
  char infix[255] = "log(100.2/2+4/(45/6))*(tan(50.464)/5^(2)-43/2)+sqrt(456)/"
                    "tan(45.003*cos(30))^(arcsin(1/10))+1";

  int status = 0;
  double s21_math = calculateExpression(infix, &status, 0);

  ck_assert_double_eq_tol(math, s21_math, 0.0001);
}
END_TEST

START_TEST(test19) {
  double math = 9423.5232095;
  char infix[255] = "1*456+34*(534-34/4*sin(65))/2+3^2";

  int status = 0;
  double s21_math = calculateExpression(infix, &status, 0);

  ck_assert_double_eq_tol(math, s21_math, 0.000001);
}
END_TEST

START_TEST(test20) {
  double math = -585.45572882;
  char infix[255] = "(23+2+1-305/3*2+4-123*sin(30)/12+23-456-1-1-1-1+-1/"
                    "34-cos(34)-3+3+3+1+2.234*3/1.234)+45/sqrt(49+51)";

  int status = 0;
  double s21_math = calculateExpression(infix, &status, 0);

  ck_assert_double_eq_tol(math, s21_math, 0.000001);
}
END_TEST

START_TEST(sin_test) {
  double math = -0.9929670;
  char infix[255] = "sin(sin(sin(sin(4235*10%232^3)+7)*3)/23)+sin(344)";

  int status = 0;
  double s21_math = calculateExpression(infix, &status, 0);

  ck_assert_double_eq_tol(math, s21_math, 0.000001);
}
END_TEST

START_TEST(cos_test) {
  double math = 0.449616;
  char infix[255] = "+cos(cos(cos(cos(435435*10%232^3)+7)*3)+25)";

  int status = 0;
  double s21_math = calculateExpression(infix, &status, 0);

  ck_assert_double_eq_tol(math, s21_math, 0.000001);
}
END_TEST

START_TEST(tan_test1) {
  double math = -2.18503986326152;
  char infix[100] = "tan(2)";

  int status = 0;
  double s21_math = calculateExpression(infix, &status, 0);

  ck_assert_double_eq_tol(s21_math, math, 0.00001);
}
END_TEST

START_TEST(tan_test2) {
  double math = 0.858595;
  char infix[255] = "~tan(~cos(tan(5^3)))";

  int status = 0;
  double s21_math = calculateExpression(infix, &status, 0);

  ck_assert_double_eq_tol(math, s21_math, 0.000001);
}
END_TEST

START_TEST(asin_test) {
  double math = -0.328158;
  char infix[255] = "asin(~0.3223)";

  int status = 0;
  double s21_math = calculateExpression(infix, &status, 0);

  ck_assert_double_eq_tol(math, s21_math, 0.000001);
}
END_TEST

START_TEST(acos_test) {
  double math = acos(0.142214);
  char infix[255] = "acos(0.142214)";

  int status = 0;
  double s21_math = calculateExpression(infix, &status, 0);

  ck_assert_double_eq_tol(math, s21_math, 0.000001);
}
END_TEST

START_TEST(atan_test) {
  double math = 0.780373;
  char infix[255] = "atan(0.99)";

  int status = 0;
  double s21_math = calculateExpression(infix, &status, 0);

  ck_assert_double_eq_tol(math, s21_math, 0.000001);
}
END_TEST

START_TEST(sqrt_test) {
  double math = -1.941967;
  char infix[255] = "~sqrt(sqrt(34058%234)/sqrt(9))";

  int status = 0;
  double s21_math = calculateExpression(infix, &status, 0);

  ck_assert_double_eq_tol(math, s21_math, 0.000001);
}
END_TEST



Suite *s21_test_suite() {
  Suite *s = suite_create("Tests");
  TCase *s21_smart_calc = tcase_create("smart");

  tcase_add_test(s21_smart_calc, random_test_1);
  tcase_add_test(s21_smart_calc, random_test_2);
  tcase_add_test(s21_smart_calc, random_test_3);
  tcase_add_test(s21_smart_calc, random_test_4);
  tcase_add_test(s21_smart_calc, random_test_5);
  tcase_add_test(s21_smart_calc, random_test_6);
  tcase_add_test(s21_smart_calc, test0);
  tcase_add_test(s21_smart_calc, test2);
  tcase_add_test(s21_smart_calc, test3);
  tcase_add_test(s21_smart_calc, test6);
  tcase_add_test(s21_smart_calc, test9);
  tcase_add_test(s21_smart_calc, test10);
  tcase_add_test(s21_smart_calc, test11);
  tcase_add_test(s21_smart_calc, test12);
  tcase_add_test(s21_smart_calc, test14);
  tcase_add_test(s21_smart_calc, sin_test);
  tcase_add_test(s21_smart_calc, tan_test1);
  tcase_add_test(s21_smart_calc, asin_test); 
  tcase_add_test(s21_smart_calc, atan_test);
  tcase_add_test(s21_smart_calc, acos_test);

  suite_add_tcase(s, s21_smart_calc);

  return s;
}

int main() {
  int no_failed = 0;

  Suite *s = s21_test_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}