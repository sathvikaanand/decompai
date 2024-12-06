
void FUN_100003c24(void)

{
  _printf("\n\nTimeout expired!\n");
                    /* WARNING: Subroutine does not return */
  _exit(1);
}


undefined4 entry(undefined4 param_1,undefined8 param_2)

{
  int iVar1;
  char *pcVar2;
  size_t sVar3;
  stat sStack_4c8;
  undefined8 local_438;
  undefined4 local_430;
  undefined4 local_42c;
  char acStack_428 [1024];
  long local_28;
  
  local_28 = *(long *)PTR____stack_chk_guard_100004010;
  local_42c = 0;
  local_438 = param_2;
  local_430 = param_1;
  _signal(0xe);
  _alarm(DAT_100008008);
  DAT_10000810c = _getuid();
  _printf("Please provide the file to access: ");
  _fflush(*(FILE **)PTR____stdoutp_100004020);
  pcVar2 = _fgets(&DAT_10000800c,0x400,*(FILE **)PTR____stdinp_100004018);
  if (pcVar2 == (char *)0x0) {
    _perror("fgets");
    local_42c = 1;
  }
  else {
    sVar3 = _strlen(&DAT_10000800c);
    if (*(char *)((long)&DAT_100008008 + sVar3 + 3) == '\n') {
      sVar3 = _strlen(&DAT_10000800c);
      *(undefined *)((long)&DAT_100008008 + sVar3 + 3) = 0;
    }
    iVar1 = _stat(&DAT_10000800c,&sStack_4c8);
    if (iVar1 == 0) {
      if (sStack_4c8.st_uid == DAT_10000810c) {
        ___snprintf_chk(acStack_428,0x400,0,0x400,"/bin/cat %s");
        _system(acStack_428);
        local_42c = 0;
      }
      else {
        _printf(
               "You do not own this file! The owner has id %d while yours is %d. Action aborted...\n"
               );
        local_42c = 1;
      }
    }
    else {
      _perror("stat");
      local_42c = 1;
    }
  }
  if (*(long *)PTR____stack_chk_guard_100004010 != local_28) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  return local_42c;
}


void ___snprintf_chk(void)

{
                    /* WARNING: Could not recover jumptable at 0x000100003e5c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR____snprintf_chk_100004000)();
  return;
}


void ___stack_chk_fail(void)

{
                    /* WARNING: Could not recover jumptable at 0x000100003e68. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR____stack_chk_fail_100004008)();
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uint _alarm(uint param_1)

{
  uint uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003e74. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)PTR__alarm_100004028)(param_1);
  return uVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _exit(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000100003e80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__exit_100004030)(param_1);
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _fflush(FILE *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003e8c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__fflush_100004038)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * _fgets(char *param_1,int param_2,FILE *param_3)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003e98. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR__fgets_100004040)(param_1,param_2);
  return pcVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uid_t _getuid(void)

{
  uid_t uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003ea4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)PTR__getuid_100004048)();
  return uVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _perror(char *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000100003eb0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__perror_100004050)();
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _printf(char *param_1,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003ebc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__printf_100004058)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _signal(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000100003ec8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__signal_100004060)(param_1);
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _stat(char *param_1,stat *param_2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003ed4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__stat_100004068)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t _strlen(char *param_1)

{
  size_t sVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003ee0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  sVar1 = (*(code *)PTR__strlen_100004070)();
  return sVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _system(char *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003eec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__system_100004078)((int)param_1);
  return iVar1;
}

