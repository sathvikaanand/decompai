
void _timeout_handler(void)

{
  _puts("\n\nTimeout expired!");
                    /* WARNING: Subroutine does not return */
  _exit(1);
}


undefined8 _verify_username(char *param_1)

{
  __darwin_ct_rune_t _Var1;
  char *pcVar2;
  undefined8 uVar3;
  size_t sVar4;
  ulong uVar5;
  
  _puts("Verifying username...");
  pcVar2 = _strstr(param_1,"%n");
  if ((pcVar2 == (char *)0x0) && (pcVar2 = _strchr(param_1,0x20), pcVar2 == (char *)0x0)) {
    _printf("Verified username: ");
    if (*param_1 != '\0') {
      uVar5 = 0;
      do {
        _Var1 = ___tolower((int)param_1[uVar5]);
        param_1[uVar5] = (char)_Var1;
        uVar5 = uVar5 + 1;
        sVar4 = _strlen(param_1);
      } while (uVar5 < sVar4);
    }
    _printf(param_1);
    uVar3 = 0;
  }
  else {
    _puts("Illegal character sequence in username!");
    uVar3 = 1;
  }
  return uVar3;
}


void entry(void)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  char *pcVar4;
  size_t sVar5;
  char *pcVar6;
  undefined8 uVar7;
  stat local_81c8;
  char acStack_8138 [255];
  char acStack_8039 [32769];
  long local_38;
  
  (*(code *)PTR____chkstk_darwin_100004000)();
  local_38 = *(long *)PTR____stack_chk_guard_100004010;
  pcVar6 = acStack_8039 + 1;
  if (_timeout != 0) {
    _signal(0xe);
    _alarm(_timeout);
  }
  _printf("Your ticket is %p... Please provide your name: ");
  puVar2 = PTR____stdoutp_100004020;
  _fflush(*(FILE **)PTR____stdoutp_100004020);
  puVar1 = PTR____stdinp_100004018;
  pcVar4 = _fgets(pcVar6,0x400,*(FILE **)PTR____stdinp_100004018);
  if (pcVar4 == (char *)0x0) {
LAB_100003ce0:
    _perror("fgets");
  }
  else {
    sVar5 = _strlen(pcVar6);
    if (pcVar6[sVar5 - 1] == '\n') {
      pcVar6[sVar5 - 1] = '\0';
    }
    iVar3 = _verify_username(pcVar6);
    if (iVar3 == 0) {
      _fflush(*(FILE **)puVar2);
      _printf("\nPlease provide the name of the file to be analyzed: ");
      _fflush(*(FILE **)puVar2);
      pcVar6 = _fgets(&_data,0x10000,*(FILE **)puVar1);
      if (pcVar6 == (char *)0x0) goto LAB_100003ce0;
      sVar5 = _strlen(&_data);
      if (*(char *)((long)&_timeout + sVar5 + 3) == '\n') {
        *(undefined *)((long)&_timeout + sVar5 + 3) = 0;
      }
      sVar5 = _strlen(&_data);
      if ((long)(sVar5 << 0x30) < 0x100000000000001) {
        ___strcpy_chk(acStack_8138,&_data,0x8100);
        iVar3 = _stat(acStack_8138,&local_81c8);
        if (iVar3 == 0) {
          _puts(acStack_8138);
          _printf("\tDevice: %d\n");
          _printf("\tI-node: %d\n");
          _printf("\tMode  : %x\n");
          _printf("\tUID   : %d\n");
          _printf("\tGID   : %d\n");
          _printf("\tSize  : %d\n");
          uVar7 = 0;
          goto LAB_100003cb0;
        }
        pcVar6 = "Access denied!";
      }
      else {
        pcVar6 = "File name too long!";
      }
    }
    else {
      pcVar6 = "Username not verified!";
    }
    _puts(pcVar6);
  }
  uVar7 = 1;
LAB_100003cb0:
  if (*(long *)PTR____stack_chk_guard_100004010 == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(uVar7);
}


void ___stack_chk_fail(void)

{
                    /* WARNING: Could not recover jumptable at 0x000100003d84. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR____stack_chk_fail_100004008)();
  return;
}


void ___strcpy_chk(void)

{
                    /* WARNING: Could not recover jumptable at 0x000100003d90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR____strcpy_chk_100004028)();
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__darwin_ct_rune_t ___tolower(__darwin_ct_rune_t param_1)

{
  __darwin_ct_rune_t _Var1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003d9c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _Var1 = (*(code *)PTR____tolower_100004030)(param_1);
  return _Var1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uint _alarm(uint param_1)

{
  uint uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003da8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)PTR__alarm_100004038)(param_1);
  return uVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _exit(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000100003db4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__exit_100004040)(param_1);
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _fflush(FILE *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003dc0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__fflush_100004048)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * _fgets(char *param_1,int param_2,FILE *param_3)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003dcc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR__fgets_100004050)(param_1,param_2);
  return pcVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _perror(char *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000100003dd8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__perror_100004058)();
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _printf(char *param_1,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003de4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__printf_100004060)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _puts(char *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003df0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__puts_100004068)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _signal(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000100003dfc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__signal_100004070)(param_1);
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _stat(char *param_1,stat *param_2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003e08. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__stat_100004078)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * _strchr(char *param_1,int param_2)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003e14. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR__strchr_100004080)(param_1,param_2);
  return pcVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t _strlen(char *param_1)

{
  size_t sVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003e20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  sVar1 = (*(code *)PTR__strlen_100004088)();
  return sVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * _strstr(char *param_1,char *param_2)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003e2c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR__strstr_100004090)();
  return pcVar1;
}


/* WARNING: Control flow encountered bad instruction data */

void ___chkstk_darwin(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

