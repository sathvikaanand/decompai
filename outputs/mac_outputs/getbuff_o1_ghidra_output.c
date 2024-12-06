
void _timeout_handler(void)

{
  _puts("\n\nTimeout expired!");
                    /* WARNING: Subroutine does not return */
  _exit(1);
}


void entry(void)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined8 uVar5;
  char *extraout_x1;
  long lVar6;
  ulong uVar7;
  char *pcVar8;
  char acStack_1468 [4096];
  char local_468 [1024];
  long local_68;
  
  iVar2 = (*(code *)PTR____chkstk_darwin_100004000)();
  puVar1 = PTR__optarg_100004078;
  pcVar8 = (char *)0x0;
  local_68 = *(long *)PTR____stack_chk_guard_100004010;
  while( true ) {
    while (iVar3 = _getopt(iVar2,extraout_x1,"t:w:d"), 0x73 < iVar3) {
      if (iVar3 == 0x74) {
        _timeout = _atoi(*(char **)puVar1);
      }
      else {
        if (iVar3 != 0x77) goto LAB_100003ca0;
        pcVar8 = _strdup(*(char **)puVar1);
      }
    }
    if (iVar3 != 100) break;
    _debug = 1;
  }
  if (iVar3 == -1) {
    if (_timeout != 0) {
      _signal(0xe);
      _alarm(_timeout);
    }
    if (pcVar8 != (char *)0x0) {
      _chdir(pcVar8);
    }
    _getcwd(acStack_1468,0x1000);
    if (_debug != 0) {
      _getuid();
      _printf("Running service %s in %s as user %d...\n");
    }
    _printf(
           "Welcome to the checksum verifier service!\n    Your service ticket id is: %p\n    Please provide the data to verify: "
           );
    puVar1 = PTR____stdoutp_100004020;
    _fflush(*(FILE **)PTR____stdoutp_100004020);
    _i = 0;
    uVar4 = _getchar();
    while (_c = (char)uVar4, (uVar4 & 0xff) != 10) {
      lVar6 = (long)(int)_i;
      local_468[lVar6] = _c;
      _i = _i + 1;
      local_468[lVar6 + 1] = '\0';
      uVar4 = _getchar();
    }
    _printf("Received a buffer of length %d\n");
    _fflush(*(FILE **)puVar1);
    _checksum = 0;
    uVar7 = (ulong)_i;
    if ((int)_i < 1) {
      _j = 0;
    }
    else {
      _checksum = 0;
      pcVar8 = local_468;
      do {
        _checksum = _checksum ^ (int)*pcVar8;
        uVar7 = uVar7 - 1;
        pcVar8 = pcVar8 + 1;
        _j = _i;
      } while (uVar7 != 0);
    }
    if (_checksum != 0) {
      _puts("Checksum failed! Exiting now...");
      _fflush(*(FILE **)puVar1);
                    /* WARNING: Subroutine does not return */
      _exit(1);
    }
    _puts("Checksum is correct!");
    _fflush(*(FILE **)puVar1);
    uVar5 = 0;
    goto LAB_100003d54;
  }
LAB_100003ca0:
  _fprintf(*(FILE **)PTR____stderrp_100004018,"Usage: %s -t <timeout> -w <workdir> [-d]\n");
  uVar5 = 1;
LAB_100003d54:
  if (*(long *)PTR____stack_chk_guard_100004010 != local_68) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail(uVar5);
  }
  return;
}


void ___stack_chk_fail(void)

{
                    /* WARNING: Could not recover jumptable at 0x000100003db8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR____stack_chk_fail_100004008)();
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uint _alarm(uint param_1)

{
  uint uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003dc4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)PTR__alarm_100004028)(param_1);
  return uVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _atoi(char *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003dd0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__atoi_100004030)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _chdir(char *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003ddc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__chdir_100004038)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _exit(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000100003de8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__exit_100004040)(param_1);
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _fflush(FILE *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003df4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__fflush_100004048)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _fprintf(FILE *param_1,char *param_2,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003e00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__fprintf_100004050)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _getchar(void)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003e0c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__getchar_100004058)();
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * _getcwd(char *param_1,size_t param_2)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003e18. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR__getcwd_100004060)();
  return pcVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _getopt(int param_1,char *param_2,char *param_3)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003e24. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__getopt_100004068)(param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uid_t _getuid(void)

{
  uid_t uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003e30. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)PTR__getuid_100004070)();
  return uVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _printf(char *param_1,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003e3c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__printf_100004080)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _puts(char *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003e48. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__puts_100004088)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _signal(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000100003e54. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__signal_100004090)(param_1);
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * _strdup(char *param_1)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003e60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR__strdup_100004098)();
  return pcVar1;
}


/* WARNING: Control flow encountered bad instruction data */

void ___chkstk_darwin(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

