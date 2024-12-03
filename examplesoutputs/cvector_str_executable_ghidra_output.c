
undefined8 entry(void)

{
  ulong local_30;
  long local_28;
  ulong local_20;
  undefined4 local_c;
  
  local_c = 0;
  _memset(&local_28,0,0x18);
  _cvec_push_str(&local_28,"Hello");
  _cvec_push_str(&local_28,"World");
  _cvec_push_str(&local_28,"CVector");
  for (local_30 = 0; local_30 < local_20; local_30 = local_30 + 1) {
    _printf("vec[%zu] = %s\n",local_30,*(undefined8 *)(local_28 + local_30 * 8));
  }
  _cvec_free_str(&local_28);
  return 0;
}


/* WARNING: Removing unreachable block (ram,0x000100000777) */

undefined8 _cvec_strdup(char *param_1)

{
  size_t sVar1;
  void *pvVar2;
  undefined8 local_10;
  
  if (param_1 == (char *)0x0) {
    local_10 = 0;
  }
  else {
    sVar1 = _strlen(param_1);
    pvVar2 = _malloc(sVar1 + 1);
    if (pvVar2 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      ___assert_rtn("cvec_strdup","cvector_str.c",0x2e,"temp != ((void *)0)");
    }
    *(undefined *)((long)pvVar2 + sVar1) = 0;
    local_10 = ___memmove_chk(pvVar2,param_1,sVar1,0xffffffffffffffff);
  }
  return local_10;
}


/* WARNING: Removing unreachable block (ram,0x000100000822) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long * _cvec_str_heap(long param_1,ulong param_2)

{
  void *pvVar1;
  ulong local_30;
  long *local_10;
  
  local_10 = (long *)_malloc(0x18);
  if (local_10 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
    ___assert_rtn("cvec_str_heap","cvector_str.c",0x45,"vec != ((void *)0)");
  }
  local_10[1] = param_1;
  local_30 = param_2;
  if ((param_2 <= (ulong)local_10[1]) && ((local_10[1] == 0 || (param_2 != local_10[1])))) {
    local_30 = local_10[1] + __CVEC_STR_START_SZ;
  }
  local_10[2] = local_30;
  pvVar1 = _malloc(local_10[2] << 3);
  *local_10 = (long)pvVar1;
  if (pvVar1 == (void *)0x0) {
    if (*local_10 == 0) {
                    /* WARNING: Subroutine does not return */
      ___assert_rtn("cvec_str_heap","cvector_str.c",0x4d,"vec->a != ((void *)0)");
    }
    _free(local_10);
    local_10 = (long *)0x0;
  }
  else {
    ___memset_chk(*local_10,0,local_10[2] << 3,0xffffffffffffffff);
  }
  return local_10;
}


/* WARNING: Removing unreachable block (ram,0x0001000009b2) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long * _cvec_init_str_heap(long param_1,ulong param_2)

{
  void *pvVar1;
  undefined8 uVar2;
  ulong local_30;
  long *local_10;
  
  local_10 = (long *)_malloc(0x18);
  if (local_10 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
    ___assert_rtn("cvec_init_str_heap","cvector_str.c",0x62,"vec != ((void *)0)");
  }
  local_10[2] = param_2 + __CVEC_STR_START_SZ;
  local_10[1] = param_2;
  pvVar1 = _malloc(local_10[2] << 3);
  *local_10 = (long)pvVar1;
  if (pvVar1 == (void *)0x0) {
    if (*local_10 == 0) {
                    /* WARNING: Subroutine does not return */
      ___assert_rtn("cvec_init_str_heap","cvector_str.c",0x69,"vec->a != ((void *)0)");
    }
    _free(local_10);
    local_10 = (long *)0x0;
  }
  else {
    for (local_30 = 0; local_30 < param_2; local_30 = local_30 + 1) {
      uVar2 = _cvec_strdup(*(undefined8 *)(param_1 + local_30 * 8));
      *(undefined8 *)(*local_10 + local_30 * 8) = uVar2;
    }
  }
  return local_10;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _cvec_str(long *param_1,long param_2,ulong param_3)

{
  void *pvVar1;
  ulong local_30;
  undefined4 local_c;
  
  param_1[1] = param_2;
  local_30 = param_3;
  if ((param_3 <= (ulong)param_1[1]) && ((param_1[1] == 0 || (param_3 != param_1[1])))) {
    local_30 = param_1[1] + __CVEC_STR_START_SZ;
  }
  param_1[2] = local_30;
  pvVar1 = _malloc(param_1[2] << 3);
  *param_1 = (long)pvVar1;
  if (pvVar1 == (void *)0x0) {
    if (*param_1 == 0) {
                    /* WARNING: Subroutine does not return */
      ___assert_rtn("cvec_str","cvector_str.c",0x7f,"vec->a != ((void *)0)");
    }
    param_1[2] = 0;
    param_1[1] = 0;
    local_c = 0;
  }
  else {
    ___memset_chk(*param_1,0,param_1[2] << 3,0xffffffffffffffff);
    local_c = 1;
  }
  return local_c;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _cvec_init_str(long *param_1,long param_2,ulong param_3)

{
  void *pvVar1;
  undefined8 uVar2;
  ulong local_30;
  undefined4 local_c;
  
  param_1[2] = param_3 + __CVEC_STR_START_SZ;
  param_1[1] = param_3;
  pvVar1 = _malloc(param_1[2] << 3);
  *param_1 = (long)pvVar1;
  if (pvVar1 == (void *)0x0) {
    if (*param_1 == 0) {
                    /* WARNING: Subroutine does not return */
      ___assert_rtn("cvec_init_str","cvector_str.c",0x94,"vec->a != ((void *)0)");
    }
    param_1[2] = 0;
    param_1[1] = 0;
    local_c = 0;
  }
  else {
    for (local_30 = 0; local_30 < param_3; local_30 = local_30 + 1) {
      uVar2 = _cvec_strdup(*(undefined8 *)(param_2 + local_30 * 8));
      *(undefined8 *)(*param_1 + local_30 * 8) = uVar2;
    }
    local_c = 1;
  }
  return local_c;
}


void _cvec_copyc_str(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  _cvec_copy_str(param_1,param_2);
  return;
}


/* WARNING: Removing unreachable block (ram,0x000100000df8) */

undefined4 _cvec_copy_str(long *param_1,long *param_2)

{
  void *pvVar1;
  undefined8 uVar2;
  int local_24;
  
  pvVar1 = _realloc((void *)*param_1,param_2[2] << 3);
  if (pvVar1 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    ___assert_rtn("cvec_copy_str","cvector_str.c",0xc4,"tmp != ((void *)0)");
  }
  *param_1 = (long)pvVar1;
  for (local_24 = 0; (ulong)(long)local_24 < (ulong)param_2[1]; local_24 = local_24 + 1) {
    uVar2 = _cvec_strdup(*(undefined8 *)(*param_2 + (long)local_24 * 8));
    *(undefined8 *)(*param_1 + (long)local_24 * 8) = uVar2;
  }
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  return 1;
}


/* WARNING: Removing unreachable block (ram,0x000100000f36) */

undefined4 _cvec_push_str(long *param_1,undefined8 param_2)

{
  long lVar1;
  void *pvVar2;
  undefined8 uVar3;
  
  if (param_1[2] == param_1[1]) {
    lVar1 = param_1[2];
    pvVar2 = _realloc((void *)*param_1,(lVar1 + 1) * 0x10);
    if (pvVar2 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      ___assert_rtn("cvec_push_str","cvector_str.c",0xdc,"tmp != ((void *)0)");
    }
    *param_1 = (long)pvVar2;
    param_1[2] = (lVar1 + 1) * 2;
  }
  uVar3 = _cvec_strdup(param_2);
  lVar1 = param_1[1];
  param_1[1] = lVar1 + 1;
  *(undefined8 *)(*param_1 + lVar1 * 8) = uVar3;
  return 1;
}


/* WARNING: Removing unreachable block (ram,0x000100001036) */

undefined4 _cvec_pushm_str(long *param_1,undefined8 param_2)

{
  long lVar1;
  void *pvVar2;
  
  if (param_1[2] == param_1[1]) {
    lVar1 = param_1[2];
    pvVar2 = _realloc((void *)*param_1,(lVar1 + 1) * 0x10);
    if (pvVar2 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      ___assert_rtn("cvec_pushm_str","cvector_str.c",0xef,"tmp != ((void *)0)");
    }
    *param_1 = (long)pvVar2;
    param_1[2] = (lVar1 + 1) * 2;
  }
  lVar1 = param_1[1];
  param_1[1] = lVar1 + 1;
  *(undefined8 *)(*param_1 + lVar1 * 8) = param_2;
  return 1;
}


void _cvec_pop_str(long *param_1,long param_2)

{
  param_1[1] = param_1[1] + -1;
  if (param_2 != 0) {
    ___strcpy_chk(param_2,*(undefined8 *)(*param_1 + param_1[1] * 8),0xffffffffffffffff);
  }
  _free(*(void **)(*param_1 + param_1[1] * 8));
  return;
}


long _cvec_back_str(long *param_1)

{
  return *param_1 + (param_1[1] + -1) * 8;
}


/* WARNING: Removing unreachable block (ram,0x0001000011d0) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _cvec_extend_str(long *param_1,long param_2)

{
  long lVar1;
  void *pvVar2;
  
  if ((ulong)param_1[2] < (ulong)(param_1[1] + param_2)) {
    lVar1 = param_1[2] + param_2 + __CVEC_STR_START_SZ;
    pvVar2 = _realloc((void *)*param_1,lVar1 * 8);
    if (pvVar2 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      ___assert_rtn("cvec_extend_str","cvector_str.c",0x116,"tmp != ((void *)0)");
    }
    *param_1 = (long)pvVar2;
    param_1[2] = lVar1;
  }
  ___memset_chk(*param_1 + param_1[1] * 8,0,param_2 << 3,0xffffffffffffffff);
  param_1[1] = param_2 + param_1[1];
  return 1;
}


/* WARNING: Removing unreachable block (ram,0x0001000012ea) */

undefined4 _cvec_insert_str(long *param_1,long param_2,undefined8 param_3)

{
  long lVar1;
  void *pvVar2;
  undefined8 uVar3;
  
  if (param_1[2] == param_1[1]) {
    lVar1 = param_1[2];
    pvVar2 = _realloc((void *)*param_1,(lVar1 + 1) * 0x10);
    if (pvVar2 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      ___assert_rtn("cvec_insert_str","cvector_str.c",0x12d,"tmp != ((void *)0)");
    }
    *param_1 = (long)pvVar2;
    param_1[2] = (lVar1 + 1) * 2;
  }
  ___memmove_chk(*param_1 + (param_2 + 1) * 8,*param_1 + param_2 * 8,(param_1[1] - param_2) * 8,
                 0xffffffffffffffff);
  uVar3 = _cvec_strdup(param_3);
  *(undefined8 *)(*param_1 + param_2 * 8) = uVar3;
  param_1[1] = param_1[1] + 1;
  return 1;
}


/* WARNING: Removing unreachable block (ram,0x00010000143a) */

undefined4 _cvec_insertm_str(long *param_1,long param_2,undefined8 param_3)

{
  long lVar1;
  void *pvVar2;
  
  if (param_1[2] == param_1[1]) {
    lVar1 = param_1[2];
    pvVar2 = _realloc((void *)*param_1,(lVar1 + 1) * 0x10);
    if (pvVar2 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      ___assert_rtn("cvec_insertm_str","cvector_str.c",0x144,"tmp != ((void *)0)");
    }
    *param_1 = (long)pvVar2;
    param_1[2] = (lVar1 + 1) * 2;
  }
  ___memmove_chk(*param_1 + (param_2 + 1) * 8,*param_1 + param_2 * 8,(param_1[1] - param_2) * 8,
                 0xffffffffffffffff);
  *(undefined8 *)(*param_1 + param_2 * 8) = param_3;
  param_1[1] = param_1[1] + 1;
  return 1;
}


/* WARNING: Removing unreachable block (ram,0x000100001588) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _cvec_insert_array_str(long *param_1,long param_2,long param_3,ulong param_4)

{
  long lVar1;
  void *pvVar2;
  undefined8 uVar3;
  ulong local_48;
  
  if ((ulong)param_1[2] < param_1[1] + param_4) {
    lVar1 = param_1[2] + param_4 + __CVEC_STR_START_SZ;
    pvVar2 = _realloc((void *)*param_1,lVar1 * 8);
    if (pvVar2 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      ___assert_rtn("cvec_insert_array_str","cvector_str.c",0x15d,"tmp != ((void *)0)");
    }
    *param_1 = (long)pvVar2;
    param_1[2] = lVar1;
  }
  ___memmove_chk(*param_1 + (param_2 + param_4) * 8,*param_1 + param_2 * 8,
                 (param_1[1] - param_2) * 8,0xffffffffffffffff);
  for (local_48 = 0; local_48 < param_4; local_48 = local_48 + 1) {
    uVar3 = _cvec_strdup(*(undefined8 *)(param_3 + local_48 * 8));
    *(undefined8 *)(*param_1 + (local_48 + param_2) * 8) = uVar3;
  }
  param_1[1] = param_4 + param_1[1];
  return 1;
}


/* WARNING: Removing unreachable block (ram,0x000100001718) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _cvec_insert_arraym_str(long *param_1,long param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  void *pvVar2;
  
  if ((ulong)param_1[2] < (ulong)(param_1[1] + param_4)) {
    lVar1 = param_1[2] + param_4 + __CVEC_STR_START_SZ;
    pvVar2 = _realloc((void *)*param_1,lVar1 * 8);
    if (pvVar2 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      ___assert_rtn("cvec_insert_arraym_str","cvector_str.c",0x177,"tmp != ((void *)0)");
    }
    *param_1 = (long)pvVar2;
    param_1[2] = lVar1;
  }
  ___memmove_chk(*param_1 + (param_2 + param_4) * 8,*param_1 + param_2 * 8,
                 (param_1[1] - param_2) * 8,0xffffffffffffffff);
  ___memmove_chk(*param_1 + param_2 * 8,param_3,param_4 << 3,0xffffffffffffffff);
  param_1[1] = param_4 + param_1[1];
  return 1;
}


void _cvec_replace_str(long *param_1,long param_2,undefined8 param_3,long param_4)

{
  undefined8 uVar1;
  
  if (param_4 != 0) {
    ___strcpy_chk(param_4,*(undefined8 *)(*param_1 + param_2 * 8),0xffffffffffffffff);
  }
  _free(*(void **)(*param_1 + param_2 * 8));
  uVar1 = _cvec_strdup(param_3);
  *(undefined8 *)(*param_1 + param_2 * 8) = uVar1;
  return;
}


void _cvec_erase_str(long *param_1,ulong param_2,ulong param_3)

{
  ulong local_28;
  
  for (local_28 = param_2; local_28 <= param_3; local_28 = local_28 + 1) {
    _free(*(void **)(*param_1 + local_28 * 8));
  }
  ___memmove_chk(*param_1 + param_2 * 8,*param_1 + (param_3 + 1) * 8,
                 ((param_1[1] + -1) - param_3) * 8,0xffffffffffffffff);
  param_1[1] = param_1[1] - ((param_3 - param_2) + 1);
  return;
}


void _cvec_remove_str(long *param_1,long param_2,long param_3)

{
  ___memmove_chk(*param_1 + param_2 * 8,*param_1 + (param_3 + 1) * 8,
                 ((param_1[1] + -1) - param_3) * 8,0xffffffffffffffff);
  param_1[1] = param_1[1] - ((param_3 - param_2) + 1);
  return;
}


/* WARNING: Removing unreachable block (ram,0x000100001a25) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _cvec_reserve_str(undefined8 *param_1,ulong param_2)

{
  void *pvVar1;
  
  if ((ulong)param_1[2] < param_2) {
    pvVar1 = _realloc((void *)*param_1,(param_2 + __CVEC_STR_START_SZ) * 8);
    if (pvVar1 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      ___assert_rtn("cvec_reserve_str","cvector_str.c",0x1b0,"tmp != ((void *)0)");
    }
    *param_1 = pvVar1;
    param_1[2] = param_2 + __CVEC_STR_START_SZ;
  }
  return 1;
}


/* WARNING: Removing unreachable block (ram,0x000100001b44) */

undefined4 _cvec_set_cap_str(long *param_1,ulong param_2)

{
  void *pvVar1;
  ulong local_28;
  
  if (param_2 < (ulong)param_1[1]) {
    local_28 = param_1[1];
    while (local_28 = local_28 - 1, param_2 - 1 < local_28) {
      _free(*(void **)(*param_1 + local_28 * 8));
    }
    param_1[1] = param_2;
  }
  pvVar1 = _realloc((void *)*param_1,param_2 << 3);
  if (pvVar1 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    ___assert_rtn("cvec_set_cap_str","cvector_str.c",0x1ca,"tmp != ((void *)0)");
  }
  *param_1 = (long)pvVar1;
  param_1[2] = param_2;
  return 1;
}


void _cvec_set_val_sz_str(long *param_1,undefined8 param_2)

{
  undefined8 uVar1;
  ulong local_20;
  
  for (local_20 = 0; local_20 < (ulong)param_1[1]; local_20 = local_20 + 1) {
    _free(*(void **)(*param_1 + local_20 * 8));
    uVar1 = _cvec_strdup(param_2);
    *(undefined8 *)(*param_1 + local_20 * 8) = uVar1;
  }
  return;
}


void _cvec_set_val_cap_str(long *param_1,undefined8 param_2)

{
  undefined8 uVar1;
  ulong local_20;
  
  for (local_20 = 0; local_20 < (ulong)param_1[2]; local_20 = local_20 + 1) {
    if (local_20 < (ulong)param_1[1]) {
      _free(*(void **)(*param_1 + local_20 * 8));
    }
    uVar1 = _cvec_strdup(param_2);
    *(undefined8 *)(*param_1 + local_20 * 8) = uVar1;
  }
  param_1[1] = param_1[2];
  return;
}


void _cvec_clear_str(long *param_1)

{
  int local_14;
  
  for (local_14 = 0; (ulong)(long)local_14 < (ulong)param_1[1]; local_14 = local_14 + 1) {
    _free(*(void **)(*param_1 + (long)local_14 * 8));
  }
  param_1[1] = 0;
  return;
}


void _cvec_free_str_heap(long *param_1)

{
  ulong local_18;
  
  if (param_1 != (long *)0x0) {
    for (local_18 = 0; local_18 < (ulong)param_1[1]; local_18 = local_18 + 1) {
      _free(*(void **)(*param_1 + local_18 * 8));
    }
    _free((void *)*param_1);
    _free(param_1);
  }
  return;
}


void _cvec_free_str(long *param_1)

{
  ulong local_18;
  
  for (local_18 = 0; local_18 < (ulong)param_1[1]; local_18 = local_18 + 1) {
    _free(*(void **)(*param_1 + local_18 * 8));
  }
  _free((void *)*param_1);
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ___assert_rtn(char *param_1,char *param_2,int param_3,char *param_4)

{
                    /* WARNING: Could not recover jumptable at 0x000100001ded. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_LAB_100002000)();
  return;
}


void ___memmove_chk(void)

{
                    /* WARNING: Could not recover jumptable at 0x000100001df3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR____assert_rtn_5_100002008)();
  return;
}


void ___memset_chk(void)

{
                    /* WARNING: Could not recover jumptable at 0x000100001df9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR____memmove_chk_5_100002010)();
  return;
}


void ___strcpy_chk(void)

{
                    /* WARNING: Could not recover jumptable at 0x000100001dff. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR____memset_chk_5_100002018)();
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _free(void *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000100001e05. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR____strcpy_chk_5_100002020)();
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * _malloc(size_t param_1)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100001e0b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = (void *)(*(code *)PTR__free_5_100002028)();
  return pvVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * _memset(void *param_1,int param_2,size_t param_3)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100001e11. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = (void *)(*(code *)PTR__malloc_5_100002030)();
  return pvVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _printf(char *param_1,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100001e17. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__memset_5_100002038)();
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * _realloc(void *param_1,size_t param_2)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100001e1d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = (void *)(*(code *)PTR__printf_5_100002040)();
  return pvVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t _strlen(char *param_1)

{
  size_t sVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100001e23. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  sVar1 = (*(code *)PTR__realloc_5_100002048)();
  return sVar1;
}

