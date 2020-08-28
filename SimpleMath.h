/*
 *
 * SimpleMath.h
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

#ifndef INCLUDE_STDIO_H
#define INCLUDE_STDIO_H

#include <stdio.h>

#endif

#ifndef INCLUDE_STDLIB_H
#define INCLUDE_STDLIB_H

#include <stdlib.h>

#endif

#ifndef INCLUDE_STRING_H
#define INCLUDE_STRING_H

#include <string.h>

#endif

#ifndef DECLARE_ELEMENT_H
#define DECLARE_ELEMENT_H

typedef struct _element {
    int totalLength;
    char * condition;
    char oper;
    float value;
    struct _element * leftSide;
    struct _element * rightSide;

    int (* cutPosition)(struct _element *);

    char * (* subString)(struct _element *, int, int);

    void (* parse)(struct _element *);

    float (* evaluate)(struct _element *);

    void (* dispose)(struct _element *);
} Element;

Element * Element_init(char *);

#endif
