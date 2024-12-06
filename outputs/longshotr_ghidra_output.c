
void FUN_1000038b4(void)

{
  _printf("\n\nTimeout expired!\n");
                    /* WARNING: Subroutine does not return */
  _exit(1);
}


undefined4 FUN_1000038d8(char *param_1)

{
  int iVar1;
  char *pcVar2;
  size_t sVar3;
  int local_24;
  undefined4 local_14;
  
  _printf("Verifying username...\n");
  pcVar2 = _strstr(param_1,"%n");
  if ((pcVar2 == (char *)0x0) && (pcVar2 = _strstr(param_1," "), pcVar2 == (char *)0x0)) {
    _printf("Verified username: ");
    for (local_24 = 0; sVar3 = _strlen(param_1), (ulong)(long)local_24 < sVar3;
        local_24 = local_24 + 1) {
      iVar1 = _tolower((int)param_1[local_24]);
      param_1[local_24] = (char)iVar1;
    }
    _printf(param_1);
    local_14 = 0;
  }
  else {
    _printf("Illegal character sequence in username!\n");
    local_14 = 1;
  }
  return local_14;
}


undefined4 entry(void)

{
  undefined *puVar1;
  int iVar2;
  char *pcVar3;
  size_t sVar4;
  char *pcVar5;
  undefined8 extraout_x1;
  stat local_81e8;
  short local_8152;
  long local_8150;
  char *local_8148;
  char *local_8140;
  undefined8 local_8138;
  undefined4 local_8130;
  undefined4 local_812c;
  char acStack_8128 [256];
  char acStack_8028 [32768];
  long local_28;
  
  local_8130 = (*(code *)PTR____chkstk_darwin_100004000)();
  puVar1 = PTR____stdoutp_100004020;
  local_28 = *(long *)PTR____stack_chk_guard_100004010;
  local_812c = 0;
  local_8140 = acStack_8128;
  local_8148 = acStack_8028;
  local_8138 = extraout_x1;
  if (DAT_100008008 != 0) {
    _signal(0xe);
    _alarm(DAT_100008008);
  }
  _printf("Your ticket is %p... Please provide your name: ");
  _fflush(*(FILE **)puVar1);
  pcVar3 = _fgets(local_8148,0x400,*(FILE **)PTR____stdinp_100004018);
  pcVar5 = local_8148;
  if (pcVar3 == (char *)0x0) {
    _perror("fgets");
    local_812c = 1;
  }
  else {
    sVar4 = _strlen(local_8148);
    pcVar3 = local_8148;
    if (pcVar5[sVar4 - 1] == '\n') {
      sVar4 = _strlen(local_8148);
      pcVar3[sVar4 - 1] = '\0';
    }
    iVar2 = FUN_1000038d8(local_8148);
    if (iVar2 == 0) {
      _fflush(*(FILE **)puVar1);
      _printf("\nPlease provide the name of the file to be analyzed: ");
      _fflush(*(FILE **)puVar1);
      pcVar5 = _fgets(&DAT_10000800c,0x10000,*(FILE **)PTR____stdinp_100004018);
      if (pcVar5 == (char *)0x0) {
        _perror("fgets");
        local_812c = 1;
      }
      else {
        sVar4 = _strlen(&DAT_10000800c);
        if (*(char *)((long)&DAT_100008008 + sVar4 + 3) == '\n') {
          sVar4 = _strlen(&DAT_10000800c);
          *(undefined *)((long)&DAT_100008008 + sVar4 + 3) = 0;
        }
        local_8150 = 0x100;
        sVar4 = _strlen(&DAT_10000800c);
        local_8152 = (short)sVar4;
        if (local_8150 < local_8152) {
          _printf("File name too long!\n");
          local_812c = 1;
        }
        else {
          ___strcpy_chk(local_8140,&DAT_10000800c,0xffffffffffffffff);
          iVar2 = _stat(local_8140,&local_81e8);
          if (iVar2 == 0) {
            _printf("%s\n");
            _printf("\tDevice: %d\n");
            _printf("\tI-node: %d\n");
            _printf("\tMode  : %x\n");
            _printf("\tUID   : %d\n");
            _printf("\tGID   : %d\n");
            _printf("\tSize  : %d\n");
            local_812c = 0;
          }
          else {
            _printf("Access denied!\n");
            local_812c = 1;
          }
        }
      }
    }
    else {
      _printf("Username not verified!\n");
      local_812c = 1;
    }
  }
  if (*(long *)PTR____stack_chk_guard_100004010 != local_28) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  return local_812c;
}


void ___stack_chk_fail(void)

{
                    /* WARNING: Could not recover jumptable at 0x000100003d98. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR____stack_chk_fail_100004008)();
  return;
}


void ___strcpy_chk(void)

{
                    /* WARNING: Could not recover jumptable at 0x000100003da4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR____strcpy_chk_100004028)();
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uint _alarm(uint param_1)

{
  uint uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003db0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)PTR__alarm_100004030)(param_1);
  return uVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _exit(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000100003dbc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__exit_100004038)(param_1);
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _fflush(FILE *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003dc8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__fflush_100004040)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * _fgets(char *param_1,int param_2,FILE *param_3)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003dd4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR__fgets_100004048)(param_1,param_2);
  return pcVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _perror(char *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000100003de0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__perror_100004050)();
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _printf(char *param_1,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003dec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__printf_100004058)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _signal(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000100003df8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__signal_100004060)(param_1);
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _stat(char *param_1,stat *param_2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003e04. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__stat_100004068)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t _strlen(char *param_1)

{
  size_t sVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003e10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  sVar1 = (*(code *)PTR__strlen_100004070)();
  return sVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * _strstr(char *param_1,char *param_2)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003e1c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR__strstr_100004078)();
  return pcVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _tolower(int _c)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003e28. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__tolower_100004080)(_c);
  return iVar1;
}


/* WARNING: Control flow encountered bad instruction data */

void ___chkstk_darwin(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

