
void FUN_10000345c(void)

{
  _printf("\n\nTimeout expired!\n");
                    /* WARNING: Subroutine does not return */
  _exit(1);
}


void FUN_100003480(char *param_1,long param_2,ulong param_3)

{
  uint uVar1;
  bool bVar2;
  size_t sVar3;
  char *pcVar4;
  long lVar5;
  ulong local_40;
  int local_34;
  uint local_30;
  uint local_2c;
  
  local_2c = 0;
  local_30 = 0;
  local_34 = 0;
  local_40 = 0;
  while( true ) {
    sVar3 = _strlen(param_1);
    bVar2 = false;
    if (local_40 < sVar3) {
      bVar2 = (ulong)(long)local_34 < param_3;
    }
    if (!bVar2) break;
    pcVar4 = _strchr("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/",
                     (int)param_1[local_40]);
    uVar1 = local_30;
    if (pcVar4 != (char *)0x0) {
      local_2c = local_2c << 6 | (int)pcVar4 - 0x3f5fU;
      uVar1 = local_30 + 6;
      if (7 < (int)(local_30 + 6)) {
        lVar5 = (long)local_34;
        local_34 = local_34 + 1;
        *(char *)(param_2 + lVar5) = (char)((int)local_2c >> (local_30 - 2 & 0x1f));
        uVar1 = local_30 - 2;
      }
    }
    local_30 = uVar1;
    local_40 = local_40 + 1;
  }
  *(undefined *)(param_2 + local_34) = 0;
  return;
}


void FUN_1000035e8(void)

{
  long lVar1;
  long lVar2;
  
  lVar1 = _opendir("./files");
  if (lVar1 == 0) {
    _perror("Could not open directory");
  }
  else {
    _printf("Files:\n");
    while (lVar2 = _readdir(lVar1), lVar2 != 0) {
      if (*(char *)(lVar2 + 0x15) != '.') {
        _printf("%s\n");
      }
    }
    _closedir(lVar1);
  }
  return;
}


void FUN_1000036ac(char *param_1)

{
  FILE *pFVar1;
  char *pcVar2;
  char acStack_128 [256];
  long local_28;
  
  local_28 = *(long *)PTR____stack_chk_guard_100004018;
  pFVar1 = _fopen(param_1,"r");
  if (pFVar1 == (FILE *)0x0) {
    _perror("Error opening file");
  }
  else {
    while (pcVar2 = _fgets(acStack_128,0x100,pFVar1), pcVar2 != (char *)0x0) {
      _printf("%s");
    }
    _fclose(pFVar1);
  }
  if (*(long *)PTR____stack_chk_guard_100004018 == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


undefined4 entry(void)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  char *extraout_x1;
  char *local_1448;
  int local_143c;
  undefined4 local_142c;
  char acStack_1428 [4096];
  undefined auStack_428 [512];
  undefined auStack_228 [255];
  undefined local_129;
  char local_128;
  undefined auStack_127 [255];
  long local_28;
  
  iVar3 = (*(code *)PTR____chkstk_darwin_100004000)();
  puVar2 = PTR____stdoutp_100004028;
  puVar1 = PTR____stderrp_100004020;
  local_28 = *(long *)PTR____stack_chk_guard_100004018;
  local_1448 = (char *)0x0;
  while (iVar4 = _getopt(iVar3,extraout_x1,"t:w:d"), iVar4 != -1) {
    if (iVar4 == 100) {
      DAT_10000800c = 1;
    }
    else if (iVar4 == 0x74) {
      DAT_100008008 = _atoi(*(char **)PTR__optarg_1000040b0);
    }
    else {
      if (iVar4 != 0x77) {
        iVar3 = _fprintf(*(FILE **)puVar1,"Usage: %s -t <timeout> -w <workdir> [-d]\n");
        local_142c = 1;
        goto LAB_100003c30;
      }
      local_1448 = _strdup(*(char **)PTR__optarg_1000040b0);
    }
  }
  if (DAT_100008008 != 0) {
    _signal(0xe);
    _alarm(DAT_100008008);
  }
  if (local_1448 != (char *)0x0) {
    _chdir(local_1448);
  }
  _getcwd(acStack_1428,0x1000);
  if (DAT_10000800c != 0) {
    _getuid();
    _printf("Running service %s in %s as user %d...\n");
  }
  while( true ) {
    while( true ) {
      while( true ) {
        while( true ) {
          _printf("Select an option:\n");
          _printf("1. List files\n");
          _printf("2. Read a file\n");
          _printf("3. Exit\n");
          _printf("Enter your choice: ");
          _fflush(*(FILE **)puVar2);
          iVar3 = _scanf("%d");
          if (iVar3 == 1) break;
          _fprintf(*(FILE **)puVar1,"Invalid input\n");
          do {
            iVar3 = _getchar();
          } while (iVar3 != 10);
        }
        if (local_143c != 1) break;
        FUN_1000035e8();
      }
      if (local_143c != 2) break;
      _printf("Enter the filename: ");
      _fflush(*(FILE **)puVar2);
      _scanf("%s");
      pcVar5 = _strstr(&local_128,"..");
      if (pcVar5 != (char *)0x0) {
        iVar3 = _fprintf(*(FILE **)puVar1,"Unsafe pattern detected!\n");
        local_142c = 1;
        goto LAB_100003c30;
      }
      if (local_128 == -0x70) {
        FUN_100003480(auStack_127,auStack_228,0x100);
        if (DAT_10000800c != 0) {
          _printf("Decoded filename: %s\n");
        }
      }
      else {
        ___strncpy_chk(auStack_228,&local_128,0xff,0x100);
        local_129 = 0;
      }
      ___snprintf_chk(auStack_428,0x200,0,0x200,"./files/%s");
      _printf("Opening file %s\n");
      FUN_1000036ac(auStack_428);
      _fflush(*(FILE **)puVar2);
    }
    if (local_143c == 3) break;
    _printf("Invalid choice. Try again.\n");
    _fflush(*(FILE **)puVar2);
  }
  _printf("Exiting...\n");
  iVar3 = _fflush(*(FILE **)puVar2);
  local_142c = 0;
LAB_100003c30:
  if (*(long *)PTR____stack_chk_guard_100004018 == local_28) {
    return local_142c;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(iVar3);
}


void ___snprintf_chk(void)

{
                    /* WARNING: Could not recover jumptable at 0x000100003c7c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR____snprintf_chk_100004008)();
  return;
}


void ___stack_chk_fail(void)

{
                    /* WARNING: Could not recover jumptable at 0x000100003c88. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR____stack_chk_fail_100004010)();
  return;
}


void ___strncpy_chk(void)

{
                    /* WARNING: Could not recover jumptable at 0x000100003c94. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR____strncpy_chk_100004030)();
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uint _alarm(uint param_1)

{
  uint uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003ca0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)PTR__alarm_100004038)(param_1);
  return uVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _atoi(char *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003cac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__atoi_100004040)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _chdir(char *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003cb8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__chdir_100004048)((int)param_1);
  return iVar1;
}


void _closedir(void)

{
                    /* WARNING: Could not recover jumptable at 0x000100003cc4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__closedir_100004050)();
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _exit(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000100003cd0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__exit_100004058)(param_1);
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _fclose(FILE *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003cdc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__fclose_100004060)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _fflush(FILE *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003ce8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__fflush_100004068)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * _fgets(char *param_1,int param_2,FILE *param_3)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003cf4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR__fgets_100004070)(param_1,param_2);
  return pcVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

FILE * _fopen(char *param_1,char *param_2)

{
  FILE *pFVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003d00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pFVar1 = (FILE *)(*(code *)PTR__fopen_100004078)();
  return pFVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _fprintf(FILE *param_1,char *param_2,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003d0c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__fprintf_100004080)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _getchar(void)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003d18. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__getchar_100004088)();
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * _getcwd(char *param_1,size_t param_2)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003d24. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR__getcwd_100004090)();
  return pcVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _getopt(int param_1,char *param_2,char *param_3)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003d30. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__getopt_100004098)(param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uid_t _getuid(void)

{
  uid_t uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003d3c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)PTR__getuid_1000040a0)();
  return uVar1;
}


void _opendir(void)

{
                    /* WARNING: Could not recover jumptable at 0x000100003d48. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__opendir_1000040a8)();
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _perror(char *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000100003d54. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__perror_1000040b8)();
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _printf(char *param_1,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003d60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__printf_1000040c0)((int)param_1);
  return iVar1;
}


void _readdir(void)

{
                    /* WARNING: Could not recover jumptable at 0x000100003d6c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__readdir_1000040c8)();
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _scanf(char *param_1,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003d78. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__scanf_1000040d0)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _signal(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000100003d84. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__signal_1000040d8)(param_1);
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * _strchr(char *param_1,int param_2)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003d90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR__strchr_1000040e0)(param_1,param_2);
  return pcVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * _strdup(char *param_1)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003d9c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR__strdup_1000040e8)();
  return pcVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t _strlen(char *param_1)

{
  size_t sVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003da8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  sVar1 = (*(code *)PTR__strlen_1000040f0)();
  return sVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * _strstr(char *param_1,char *param_2)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003db4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR__strstr_1000040f8)();
  return pcVar1;
}


/* WARNING: Control flow encountered bad instruction data */

void ___chkstk_darwin(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

