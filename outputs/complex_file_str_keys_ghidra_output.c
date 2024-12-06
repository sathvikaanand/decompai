
ulong _hash(byte *param_1,ulong param_2)

{
  uint local_1c;
  byte *local_10;
  
  local_1c = 0x1505;
  for (local_10 = param_1; *local_10 != 0; local_10 = local_10 + 1) {
    local_1c = local_1c * 0x21 + (uint)*local_10;
  }
  return (ulong)local_1c % param_2 & 0xffffffff;
}


undefined8 * _create_table(size_t param_1)

{
  undefined8 *puVar1;
  void *pvVar2;
  
  puVar1 = (undefined8 *)_malloc(0x18);
  pvVar2 = _calloc(param_1,8);
  *puVar1 = pvVar2;
  puVar1[1] = param_1;
  puVar1[2] = 0;
  return puVar1;
}


undefined8 * _create_entry(char *param_1,undefined4 param_2)

{
  undefined8 *puVar1;
  char *pcVar2;
  
  puVar1 = (undefined8 *)_malloc(0x18);
  pcVar2 = _strdup(param_1);
  *puVar1 = pcVar2;
  *(undefined4 *)(puVar1 + 1) = param_2;
  puVar1[2] = 0;
  return puVar1;
}


void _resize_table(long *param_1)

{
  undefined8 *puVar1;
  uint uVar2;
  size_t sVar3;
  void *pvVar4;
  undefined8 *local_30;
  ulong local_28;
  
  sVar3 = param_1[1] << 1;
  pvVar4 = _calloc(sVar3,8);
  for (local_28 = 0; local_28 < (ulong)param_1[1]; local_28 = local_28 + 1) {
    local_30 = *(undefined8 **)(*param_1 + local_28 * 8);
    while (local_30 != (undefined8 *)0x0) {
      uVar2 = _hash(*local_30,sVar3);
      puVar1 = (undefined8 *)local_30[2];
      local_30[2] = *(undefined8 *)((long)pvVar4 + (ulong)uVar2 * 8);
      *(undefined8 **)((long)pvVar4 + (ulong)uVar2 * 8) = local_30;
      local_30 = puVar1;
    }
  }
  _free((void *)*param_1);
  *param_1 = (long)pvVar4;
  param_1[1] = sVar3;
  return;
}


void _insert(long *param_1,char *param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  float local_44;
  float local_34;
  undefined8 *local_28;
  
  local_34 = (float)(ulong)param_1[2];
  local_44 = (float)(ulong)param_1[1];
  if (DAT_100000ec0 <= (double)(local_34 / local_44)) {
    _resize_table(param_1);
  }
  uVar1 = _hash(param_2,param_1[1]);
  local_28 = *(undefined8 **)(*param_1 + (ulong)uVar1 * 8);
  while( true ) {
    if (local_28 == (undefined8 *)0x0) {
      lVar3 = _create_entry(param_2,param_3);
      *(undefined8 *)(lVar3 + 0x10) = *(undefined8 *)(*param_1 + (ulong)uVar1 * 8);
      *(long *)(*param_1 + (ulong)uVar1 * 8) = lVar3;
      param_1[2] = param_1[2] + 1;
      return;
    }
    iVar2 = _strcmp((char *)*local_28,param_2);
    if (iVar2 == 0) break;
    local_28 = (undefined8 *)local_28[2];
  }
  *(undefined4 *)(local_28 + 1) = param_3;
  return;
}


undefined4 _get(long *param_1,char *param_2)

{
  uint uVar1;
  int iVar2;
  undefined8 *local_30;
  
  uVar1 = _hash(param_2,param_1[1]);
  local_30 = *(undefined8 **)(*param_1 + (ulong)uVar1 * 8);
  while( true ) {
    if (local_30 == (undefined8 *)0x0) {
      _fprintf(*(FILE **)PTR____stderrp_100001000,"Key \'%s\' not found.\n",param_2);
      return 0xffffffff;
    }
    iVar2 = _strcmp((char *)*local_30,param_2);
    if (iVar2 == 0) break;
    local_30 = (undefined8 *)local_30[2];
  }
  return *(undefined4 *)(local_30 + 1);
}


void _delete(long *param_1,char *param_2)

{
  uint uVar1;
  int iVar2;
  undefined8 *local_30;
  undefined8 *local_28;
  
  uVar1 = _hash(param_2,param_1[1]);
  local_28 = *(undefined8 **)(*param_1 + (ulong)uVar1 * 8);
  local_30 = (undefined8 *)0x0;
  while( true ) {
    if (local_28 == (undefined8 *)0x0) {
      _fprintf(*(FILE **)PTR____stderrp_100001000,"Key \'%s\' not found for deletion.\n",param_2);
      return;
    }
    iVar2 = _strcmp((char *)*local_28,param_2);
    if (iVar2 == 0) break;
    local_30 = local_28;
    local_28 = (undefined8 *)local_28[2];
  }
  if (local_30 == (undefined8 *)0x0) {
    *(undefined8 *)(*param_1 + (ulong)uVar1 * 8) = local_28[2];
  }
  else {
    local_30[2] = local_28[2];
  }
  _free((void *)*local_28);
  _free(local_28);
  param_1[2] = param_1[2] + -1;
  return;
}


void _print_table(long *param_1)

{
  undefined8 *local_20;
  ulong local_18;
  
  for (local_18 = 0; local_18 < (ulong)param_1[1]; local_18 = local_18 + 1) {
    _printf("Bucket %zu: ",local_18);
    for (local_20 = *(undefined8 **)(*param_1 + local_18 * 8); local_20 != (undefined8 *)0x0;
        local_20 = (undefined8 *)local_20[2]) {
      _printf("(\'%s\' -> %d) ",*local_20,(ulong)*(uint *)(local_20 + 1));
    }
    _printf("\n");
  }
  return;
}


void _free_table(long *param_1)

{
  undefined8 *puVar1;
  undefined8 *local_20;
  ulong local_18;
  
  for (local_18 = 0; local_18 < (ulong)param_1[1]; local_18 = local_18 + 1) {
    local_20 = *(undefined8 **)(*param_1 + local_18 * 8);
    while (local_20 != (undefined8 *)0x0) {
      puVar1 = (undefined8 *)local_20[2];
      _free((void *)*local_20);
      _free(local_20);
      local_20 = puVar1;
    }
  }
  _free((void *)*param_1);
  _free(param_1);
  return;
}


undefined8 entry(void)

{
  uint uVar1;
  undefined8 uVar2;
  
  uVar2 = _create_table(0x10);
  _insert(uVar2,"apple",10);
  _insert(uVar2,"banana",0x14);
  _insert(uVar2,"cherry",0x1e);
  _insert(uVar2,"date",0x28);
  _insert(uVar2,"elderberry",0x32);
  _printf("Hash table after insertion:\n");
  _print_table(uVar2);
  uVar1 = _get(uVar2,"cherry");
  _printf("Value for key \'cherry\': %d\n",(ulong)uVar1);
  _delete(uVar2,"cherry");
  _printf("Hash table after deleting key \'cherry\':\n");
  _print_table(uVar2);
  _free_table(uVar2);
  return 0;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * _calloc(size_t param_1,size_t param_2)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000e95. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = (void *)(*(code *)PTR_LAB_100001008)();
  return pvVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _fprintf(FILE *param_1,char *param_2,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000e9b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__calloc_5_100001010)();
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _free(void *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000100000ea1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__fprintf_5_100001018)();
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * _malloc(size_t param_1)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000ea7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = (void *)(*(code *)PTR__free_5_100001020)();
  return pvVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _printf(char *param_1,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000ead. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__malloc_5_100001028)();
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _strcmp(char *param_1,char *param_2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000eb3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__printf_5_100001030)();
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * _strdup(char *param_1)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000eb9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR__strcmp_5_100001038)();
  return pcVar1;
}

