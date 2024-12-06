
undefined8 entry(void)

{
  ulong local_40;
  ulong local_38;
  int local_2c;
  void *local_28;
  ulong local_20;
  ulong local_18;
  undefined4 local_c;
  
  local_c = 0;
  _memset(&local_28,0,0x18);
  for (local_2c = 0; local_2c < 5; local_2c = local_2c + 1) {
    if (local_20 == local_18) {
      if (local_18 == 0) {
        local_40 = 1;
      }
      else {
        local_40 = local_18 << 1;
      }
      local_18 = local_40;
      local_28 = _realloc(local_28,local_40 << 2);
    }
    *(int *)((long)local_28 + local_20 * 4) = local_2c;
    local_20 = local_20 + 1;
  }
  for (local_38 = 0; local_38 < local_20; local_38 = local_38 + 1) {
    _printf("vec[%zu] = %d\n",local_38,(ulong)*(uint *)((long)local_28 + local_38 * 4));
  }
  _free(local_28);
  return 0;
}


/* WARNING: Removing unreachable block (ram,0x000100001052) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long * _cvec_i_heap(long param_1,ulong param_2)

{
  void *pvVar1;
  ulong local_30;
  long *local_10;
  
  local_10 = (long *)_malloc(0x18);
  if (local_10 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
    ___assert_rtn("cvec_i_heap","cvector_i.c",0x2c,"vec != ((void *)0)");
  }
  local_10[1] = param_1;
  local_30 = param_2;
  if ((param_2 <= (ulong)local_10[1]) && ((local_10[1] == 0 || (param_2 != local_10[1])))) {
    local_30 = local_10[1] + __CVEC_I_START_SZ;
  }
  local_10[2] = local_30;
  pvVar1 = _malloc(local_10[2] << 2);
  *local_10 = (long)pvVar1;
  if (pvVar1 == (void *)0x0) {
    if (*local_10 == 0) {
                    /* WARNING: Subroutine does not return */
      ___assert_rtn("cvec_i_heap","cvector_i.c",0x34,"vec->a != ((void *)0)");
    }
    _free(local_10);
    local_10 = (long *)0x0;
  }
  return local_10;
}


/* WARNING: Removing unreachable block (ram,0x0001000011c2) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long * _cvec_init_i_heap(undefined8 param_1,long param_2)

{
  void *pvVar1;
  long *local_10;
  
  local_10 = (long *)_malloc(0x18);
  if (local_10 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
    ___assert_rtn("cvec_init_i_heap","cvector_i.c",0x44,"vec != ((void *)0)");
  }
  local_10[2] = param_2 + __CVEC_I_START_SZ;
  local_10[1] = param_2;
  pvVar1 = _malloc(local_10[2] << 2);
  *local_10 = (long)pvVar1;
  if (pvVar1 == (void *)0x0) {
    if (*local_10 == 0) {
                    /* WARNING: Subroutine does not return */
      ___assert_rtn("cvec_init_i_heap","cvector_i.c",0x4b,"vec->a != ((void *)0)");
    }
    _free(local_10);
    local_10 = (long *)0x0;
  }
  else {
    ___memmove_chk(*local_10,param_1,param_2 << 2,0xffffffffffffffff);
  }
  return local_10;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _cvec_i(long *param_1,long param_2,ulong param_3)

{
  void *pvVar1;
  ulong local_30;
  undefined4 local_c;
  
  param_1[1] = param_2;
  local_30 = param_3;
  if ((param_3 <= (ulong)param_1[1]) && ((param_1[1] == 0 || (param_3 != param_1[1])))) {
    local_30 = param_1[1] + __CVEC_I_START_SZ;
  }
  param_1[2] = local_30;
  pvVar1 = _malloc(param_1[2] << 2);
  *param_1 = (long)pvVar1;
  if (pvVar1 == (void *)0x0) {
    if (*param_1 == 0) {
                    /* WARNING: Subroutine does not return */
      ___assert_rtn("cvec_i","cvector_i.c",0x5f,"vec->a != ((void *)0)");
    }
    param_1[2] = 0;
    param_1[1] = 0;
    local_c = 0;
  }
  else {
    local_c = 1;
  }
  return local_c;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _cvec_init_i(long *param_1,undefined8 param_2,long param_3)

{
  void *pvVar1;
  undefined4 local_c;
  
  param_1[2] = param_3 + __CVEC_I_START_SZ;
  param_1[1] = param_3;
  pvVar1 = _malloc(param_1[2] << 2);
  *param_1 = (long)pvVar1;
  if (pvVar1 == (void *)0x0) {
    if (*param_1 == 0) {
                    /* WARNING: Subroutine does not return */
      ___assert_rtn("cvec_init_i","cvector_i.c",0x6f,"vec->a != ((void *)0)");
    }
    param_1[2] = 0;
    param_1[1] = 0;
    local_c = 0;
  }
  else {
    ___memmove_chk(*param_1,param_2,param_3 << 2,0xffffffffffffffff);
    local_c = 1;
  }
  return local_c;
}


void _cvec_copyc_i(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  _cvec_copy_i(param_1,param_2);
  return;
}


/* WARNING: Removing unreachable block (ram,0x000100001588) */

undefined4 _cvec_copy_i(undefined8 *param_1,undefined8 *param_2)

{
  void *pvVar1;
  
  pvVar1 = _realloc((void *)*param_1,param_2[2] << 2);
  if (pvVar1 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    ___assert_rtn("cvec_copy_i","cvector_i.c",0x9c,"tmp != ((void *)0)");
  }
  *param_1 = pvVar1;
  ___memmove_chk(*param_1,*param_2,param_2[1] << 2,0xffffffffffffffff);
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  return 1;
}


/* WARNING: Removing unreachable block (ram,0x000100001695) */

undefined4 _cvec_push_i(long *param_1,undefined4 param_2)

{
  long lVar1;
  void *pvVar2;
  
  if (param_1[2] == param_1[1]) {
    lVar1 = param_1[2];
    pvVar2 = _realloc((void *)*param_1,(lVar1 + 1) * 8);
    if (pvVar2 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      ___assert_rtn("cvec_push_i","cvector_i.c",0xb2,"tmp != ((void *)0)");
    }
    *param_1 = (long)pvVar2;
    param_1[2] = (lVar1 + 1) * 2;
  }
  lVar1 = param_1[1];
  param_1[1] = lVar1 + 1;
  *(undefined4 *)(*param_1 + lVar1 * 4) = param_2;
  return 1;
}


undefined4 _cvec_pop_i(long *param_1)

{
  long lVar1;
  
  lVar1 = param_1[1];
  param_1[1] = lVar1 + -1;
  return *(undefined4 *)(*param_1 + -4 + lVar1 * 4);
}


long _cvec_back_i(long *param_1)

{
  return *param_1 + (param_1[1] + -1) * 4;
}


/* WARNING: Removing unreachable block (ram,0x0001000017f0) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _cvec_extend_i(undefined8 *param_1,long param_2)

{
  long lVar1;
  void *pvVar2;
  
  if ((ulong)param_1[2] < (ulong)(param_1[1] + param_2)) {
    lVar1 = param_1[2] + param_2 + __CVEC_I_START_SZ;
    pvVar2 = _realloc((void *)*param_1,lVar1 * 4);
    if (pvVar2 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      ___assert_rtn("cvec_extend_i","cvector_i.c",0xd2,"tmp != ((void *)0)");
    }
    *param_1 = pvVar2;
    param_1[2] = lVar1;
  }
  param_1[1] = param_2 + param_1[1];
  return 1;
}


/* WARNING: Removing unreachable block (ram,0x0001000018d9) */

undefined4 _cvec_insert_i(long *param_1,long param_2,undefined4 param_3)

{
  long lVar1;
  void *pvVar2;
  
  if (param_1[2] == param_1[1]) {
    lVar1 = param_1[2];
    pvVar2 = _realloc((void *)*param_1,(lVar1 + 1) * 8);
    if (pvVar2 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      ___assert_rtn("cvec_insert_i","cvector_i.c",0xe8,"tmp != ((void *)0)");
    }
    *param_1 = (long)pvVar2;
    param_1[2] = (lVar1 + 1) * 2;
  }
  ___memmove_chk(*param_1 + (param_2 + 1) * 4,*param_1 + param_2 * 4,(param_1[1] - param_2) * 4,
                 0xffffffffffffffff);
  *(undefined4 *)(*param_1 + param_2 * 4) = param_3;
  param_1[1] = param_1[1] + 1;
  return 1;
}


/* WARNING: Removing unreachable block (ram,0x000100001a28) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _cvec_insert_array_i(long *param_1,long param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  void *pvVar2;
  
  if ((ulong)param_1[2] < (ulong)(param_1[1] + param_4)) {
    lVar1 = param_1[2] + param_4 + __CVEC_I_START_SZ;
    pvVar2 = _realloc((void *)*param_1,lVar1 * 4);
    if (pvVar2 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      ___assert_rtn("cvec_insert_array_i","cvector_i.c",0x102,"tmp != ((void *)0)");
    }
    *param_1 = (long)pvVar2;
    param_1[2] = lVar1;
  }
  ___memmove_chk(*param_1 + (param_2 + param_4) * 4,*param_1 + param_2 * 4,
                 (param_1[1] - param_2) * 4,0xffffffffffffffff);
  ___memmove_chk(*param_1 + param_2 * 4,param_3,param_4 << 2,0xffffffffffffffff);
  param_1[1] = param_4 + param_1[1];
  return 1;
}


undefined4 _cvec_replace_i(long *param_1,long param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(*param_1 + param_2 * 4);
  *(undefined4 *)(*param_1 + param_2 * 4) = param_3;
  return uVar1;
}


void _cvec_erase_i(long *param_1,long param_2,long param_3)

{
  ___memmove_chk(*param_1 + param_2 * 4,*param_1 + (param_3 + 1) * 4,
                 ((param_1[1] + -1) - param_3) * 4,0xffffffffffffffff);
  param_1[1] = param_1[1] - ((param_3 - param_2) + 1);
  return;
}


/* WARNING: Removing unreachable block (ram,0x000100001c35) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _cvec_reserve_i(undefined8 *param_1,ulong param_2)

{
  void *pvVar1;
  
  if ((ulong)param_1[2] < param_2) {
    pvVar1 = _realloc((void *)*param_1,(param_2 + __CVEC_I_START_SZ) * 4);
    if (pvVar1 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      ___assert_rtn("cvec_reserve_i","cvector_i.c",0x129,"tmp != ((void *)0)");
    }
    *param_1 = pvVar1;
    param_1[2] = param_2 + __CVEC_I_START_SZ;
  }
  return 1;
}


/* WARNING: Removing unreachable block (ram,0x000100001d0a) */

undefined4 _cvec_set_cap_i(undefined8 *param_1,ulong param_2)

{
  void *pvVar1;
  
  if (param_2 < (ulong)param_1[1]) {
    param_1[1] = param_2;
  }
  pvVar1 = _realloc((void *)*param_1,param_2 << 2);
  if (pvVar1 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    ___assert_rtn("cvec_set_cap_i","cvector_i.c",0x13e,"tmp != ((void *)0)");
  }
  *param_1 = pvVar1;
  param_1[2] = param_2;
  return 1;
}


void _cvec_set_val_sz_i(long *param_1,undefined4 param_2)

{
  ulong local_20;
  
  for (local_20 = 0; local_20 < (ulong)param_1[1]; local_20 = local_20 + 1) {
    *(undefined4 *)(*param_1 + local_20 * 4) = param_2;
  }
  return;
}


void _cvec_set_val_cap_i(long *param_1,undefined4 param_2)

{
  ulong local_20;
  
  for (local_20 = 0; local_20 < (ulong)param_1[2]; local_20 = local_20 + 1) {
    *(undefined4 *)(*param_1 + local_20 * 4) = param_2;
  }
  return;
}


void _cvec_clear_i(long param_1)

{
  *(undefined8 *)(param_1 + 8) = 0;
  return;
}


void _cvec_free_i_heap(undefined8 *param_1)

{
  if (param_1 != (undefined8 *)0x0) {
    _free((void *)*param_1);
    _free(param_1);
  }
  return;
}


void _cvec_free_i(undefined8 *param_1)

{
  _free((void *)*param_1);
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ___assert_rtn(char *param_1,char *param_2,int param_3,char *param_4)

{
                    /* WARNING: Could not recover jumptable at 0x000100001e8e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR____assert_rtn_100002000)();
  return;
}


void ___memmove_chk(void)

{
                    /* WARNING: Could not recover jumptable at 0x000100001e94. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR____memmove_chk_100002008)();
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _free(void *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000100001e9a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__free_100002010)();
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * _malloc(size_t param_1)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100001ea0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = (void *)(*(code *)PTR__malloc_100002018)();
  return pvVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * _memset(void *param_1,int param_2,size_t param_3)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100001ea6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = (void *)(*(code *)PTR__memset_100002020)();
  return pvVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _printf(char *param_1,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100001eac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__printf_100002028)();
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * _realloc(void *param_1,size_t param_2)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100001eb2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = (void *)(*(code *)PTR__realloc_100002030)();
  return pvVar1;
}

