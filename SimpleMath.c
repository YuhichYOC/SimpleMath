/*
 *
 * SimpleMath.c
 *
 * Copyright 2020 Yuichi Yoshii
 *     吉井雄一 @ 吉井産業  you.65535.kir@gmail.com
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include "SimpleMath.h"

int Element_cutPosition(Element * e) {
    for (int i = e->totalLength - 1; 0 < i; --i) {
        if ('+' == e->condition[i]) {
            return i;
        }
        if ('-' == e->condition[i]) {
            return i;
        }
    }
    for (int j = e->totalLength - 1; 0 < j; --j) {
        if ('*' == e->condition[j]) {
            return j;
        }
        if ('/' == e->condition[j]) {
            return j;
        }
    }
    return -1;
}

char * Element_subString(Element * e, int start, int end) {
    char * ret = (char *) malloc(end - start + 1);
    memset(ret, 0, end - start + 1);
    for (int i = start; end > i; ++i) {
        ret[i - start] = e->condition[i];
    }
    return ret;
}

void Element_parse(Element * e) {
    int cutpos = e->cutPosition(e);
    if (-1 == cutpos) {
        e->value = atof(e->condition);
    }
    else {
        e->oper = e->subString(e, cutpos, cutpos + 1)[0];
        e->leftSide = Element_init(e->subString(e, 0, cutpos));
        e->leftSide->parse(e->leftSide);
        e->rightSide = Element_init(e->subString(e, cutpos + 1, e->totalLength));
        e->rightSide->parse(e->rightSide);
    }
}

float Element_evaluate(Element * e) {
    if (' ' == e->oper) {
        return e->value;
    }
    float leftValue = e->leftSide->evaluate(e->leftSide);
    float rightValue = e->rightSide->evaluate(e->rightSide);
    switch (e->oper) {
        case '+':
            return leftValue + rightValue;
        case '-':
            return leftValue - rightValue;
        case '*':
            return leftValue * rightValue;
        default:
            return leftValue / rightValue;
    }
}

void Element_dispose(Element * e) {
    if (' ' != e->oper) {
        e->leftSide->dispose(e->leftSide);
        e->rightSide->dispose(e->rightSide);
    }
    free(e->condition);
    free(e);
}

Element * Element_init(char * condition) {
    Element * e = (Element *) malloc(sizeof(Element));
    e->totalLength = strlen(condition);
    e->condition = (char *) malloc(e->totalLength + 1);
    memset(e->condition, 0, e->totalLength + 1);
    strcpy(e->condition, condition);
    e->oper = ' ';
    e->cutPosition = Element_cutPosition;
    e->subString = Element_subString;
    e->parse = Element_parse;
    e->evaluate = Element_evaluate;
    e->dispose = Element_dispose;
    return e;
}
