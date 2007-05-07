
/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */




#include <stdlib.h>
#include <stdio.h>
#include <axutil_env.h>
#include "c14n_sorted_list.h"

/*
 * Quick and dirty hack for a sorted list. This must later be
 * reimplemented
 * */

void
sorted_list_iterate(
    c14n_sorted_list_t *root,
    const void *ctx,
    void(*perform)(const void *, const void *),
    const axutil_env_t *env
)
{
    if (!root) return;
    if(root->left) sorted_list_iterate(root->left, ctx, perform, env);
    perform(root->val, ctx);
    if(root->right) sorted_list_iterate(root->right, ctx, perform, env);
}

void
sorted_list_insert(
    c14n_sorted_list_t **node,
    void *val,
    const void *ctx,
    int(*compar)(const void *, const void *, const void *)
)
{
    if(!(*node)) {
        *node = (c14n_sorted_list_t *) malloc(sizeof(node));
        (*node)->left = (*node)->right = NULL;
        (*node)->val = val;
        return;
    }

    if(compar(val, (*node)->val, ctx)<0)
        sorted_list_insert(&(*node)->left, val, ctx, compar);
    else if(compar(val, (*node)->val, ctx)>0)
        sorted_list_insert(&(*node)->right, val, ctx, compar);
    else; /*neglect if the same ns*/
}

void
sorted_list_free_container(
    c14n_sorted_list_t *root,
    const axutil_env_t *env
)
{
    if (!root) return;
    if (root->left)
    {
        sorted_list_free_container(root->left, env);
        AXIS2_FREE(env->allocator, root->left);
    }
    if (root->right)
    {
        sorted_list_free_container(root->right, env);
        AXIS2_FREE(env->allocator, root->right);
    }
    /*if (root) AXIS2_FREE(env->allocator, root);*/
}

void
sorted_list_free(
    c14n_sorted_list_t *root,
    void(*free)(const void *, const void *),
    const axutil_env_t *env
)
{
    sorted_list_iterate(root, NULL, free, env);
}
/*
void print_str(const void* p)
{
    printf("%s\n", (char *)p);
}
 
void printout(c14n_sorted_list_t * sorted_list) 
{
    sorted_list_iterate(sorted_list, print_str);
}
 
static int
cmpstringp(
    const void *p1,
    const void *p2
    )
{
    return strcmp((char *) p1, (char *) p2);
}
 
 
int main() {
   c14n_sorted_list_t * curr, * root;
 
   root = c14n_sorted_list_create(curr);
   char *c1 = "aaa";
   char *c2 = "bac";
   char *c3 = "aaaaaa";
   char *c4 = "bab";
   char *c5 = "aca";
   char *c6 = "babaaa";
 
   AXIS2_SORTED_LIST_INSERT(&root, (void *) c1, cmpstringp, env);
   AXIS2_SORTED_LIST_INSERT(&root, (void *) c2, cmpstringp, env);
   AXIS2_SORTED_LIST_INSERT(&root, (void *) c3, cmpstringp, env);
   AXIS2_SORTED_LIST_INSERT(&root, (void *) c4, cmpstringp, env);
   AXIS2_SORTED_LIST_INSERT(&root, (void *) c5, cmpstringp, env);
   AXIS2_SORTED_LIST_INSERT(&root, (void *) c6, cmpstringp, env);
   printout(root);
   return 0;
}
 
*/
