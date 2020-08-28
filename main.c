#include "SimpleMath.h"

float run(char * condition) {
    Element * e = Element_init(condition);
    e->parse(e);
    float ret = e->evaluate(e);
    e->dispose(e);
    return ret;
}

void testRun01() {
    char condition[] = "1+2";
    float ret = run(condition);
    printf("testRun01 : %f\n", ret);
}

void testRun02() {
    char condition[] = "1+2-3";
    float ret = run(condition);
    printf("testRun02 : %f\n", ret);
}

void testRun03() {
    char condition[] = "2*3";
    float ret = run(condition);
    printf("testRun03 : %f\n", ret);
}

void testRun04() {
    char condition[] = "6/2";
    float ret = run(condition);
    printf("testRun04 : %f\n", ret);
}

void testRun05() {
    char condition[] = "1+2*5-8/2";
    float ret = run(condition);
    printf("testRun05 : %f\n", ret);
}

int main(void) {
    testRun01();
    testRun02();
    testRun03();
    testRun04();
    testRun05();
    return 0;
}
