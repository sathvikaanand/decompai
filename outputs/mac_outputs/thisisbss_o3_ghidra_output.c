
void _timeout_handler(void)

{
  _puts("\n\nTimeout expired!");
                    /* WARNING: Subroutine does not return */
  _exit(1);
}


void entry(void)

{
  int iVar1;
  char *pcVar2;
  size_t sVar3;
  undefined8 uVar4;
  stat sStack_4c8;
  char acStack_438 [1024];
  long local_38;
  
  local_38 = *(long *)PTR____stack_chk_guard_100004008;
  _signal(0xe);
  _alarm(_timeout);
  _user_id = _getuid();
  _printf("Please provide the file to access: ");
  _fflush(*(FILE **)PTR____stdoutp_100004018);
  pcVar2 = _fgets(&_filename,0x400,*(FILE **)PTR____stdinp_100004010);
  if (pcVar2 == (char *)0x0) {
    pcVar2 = "fgets";
LAB_100003e18:
    _perror(pcVar2);
  }
  else {
    sVar3 = _strlen(&_filename);
    if (*(char *)((long)&_timeout + sVar3 + 3) == '\n') {
      *(undefined *)((long)&_timeout + sVar3 + 3) = 0;
    }
    iVar1 = _stat(&_filename,&sStack_4c8);
    if (iVar1 != 0) {
      pcVar2 = "stat";
      goto LAB_100003e18;
    }
    if (sStack_4c8.st_uid == _user_id) {
      _snprintf(acStack_438,0x400,"/bin/cat %s");
      _system(acStack_438);
      uVar4 = 0;
      if (*(long *)PTR____stack_chk_guard_100004008 == local_38) {
        return;
      }
      goto LAB_100003dec;
    }
    _printf("You do not own this file! The owner has id %d while yours is %d. Action aborted...\n");
  }
  uVar4 = 1;
  if (*(long *)PTR____stack_chk_guard_100004008 == local_38) {
    return;
  }
LAB_100003dec:
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(uVar4);
}


void ___stack_chk_fail(void)

{
                    /* WARNING: Could not recover jumptable at 0x000100003e54. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR____stack_chk_fail_100004000)();
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uint _alarm(uint param_1)

{
  uint uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003e60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)PTR__alarm_100004020)(param_1);
  return uVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _exit(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000100003e6c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__exit_100004028)(param_1);
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _fflush(FILE *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003e78. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__fflush_100004030)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * _fgets(char *param_1,int param_2,FILE *param_3)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003e84. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR__fgets_100004038)(param_1,param_2);
  return pcVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uid_t _getuid(void)

{
  uid_t uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003e90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)PTR__getuid_100004040)();
  return uVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _perror(char *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000100003e9c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__perror_100004048)();
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _printf(char *param_1,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003ea8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__printf_100004050)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _puts(char *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003eb4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__puts_100004058)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _signal(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000100003ec0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__signal_100004060)(param_1);
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _snprintf(char *param_1,size_t param_2,char *param_3,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003ecc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__snprintf_100004068)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _stat(char *param_1,stat *param_2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003ed8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__stat_100004070)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t _strlen(char *param_1)

{
  size_t sVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003ee4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  sVar1 = (*(code *)PTR__strlen_100004078)();
  return sVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _system(char *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003ef0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__system_100004080)((int)param_1);
  return iVar1;
}

