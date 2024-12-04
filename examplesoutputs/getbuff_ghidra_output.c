
void FUN_1000039a0(void)

{
  _printf("\n\nTimeout expired!\n");
                    /* WARNING: Subroutine does not return */
  _exit(1);
}


undefined4 entry(void)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  char *extraout_x1;
  char *local_1448;
  undefined4 local_142c;
  char acStack_1428 [4096];
  char local_428 [1024];
  long local_28;
  
  iVar2 = (*(code *)PTR____chkstk_darwin_100004000)();
  puVar1 = PTR____stdoutp_100004020;
  local_28 = *(long *)PTR____stack_chk_guard_100004010;
  local_1448 = (char *)0x0;
LAB_100003a48:
  do {
    iVar3 = _getopt(iVar2,extraout_x1,"t:w:d");
    if (iVar3 == -1) {
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
      _printf(
             "Welcome to the checksum verifier service!\n    Your service ticket id is: %p\n    Please provide the data to verify: "
             );
      _fflush(*(FILE **)puVar1);
      DAT_100008018 = 0;
      while( true ) {
        iVar2 = _getchar();
        DAT_100008010 = (char)iVar2;
        if (DAT_100008010 == '\n') break;
        local_428[DAT_100008018] = DAT_100008010;
        local_428[DAT_100008018 + 1] = '\0';
        DAT_100008018 = DAT_100008018 + 1;
      }
      _printf("Received a buffer of length %d\n");
      _fflush(*(FILE **)puVar1);
      DAT_100008014 = 0;
      for (DAT_10000801c = 0; DAT_10000801c < DAT_100008018; DAT_10000801c = DAT_10000801c + 1) {
        DAT_100008014 = DAT_100008014 ^ (int)local_428[DAT_10000801c];
      }
      if (DAT_100008014 != 0) {
        _printf("Checksum failed! Exiting now...\n");
        _fflush(*(FILE **)puVar1);
                    /* WARNING: Subroutine does not return */
        _exit(1);
      }
      _printf("Checksum is correct!\n");
      iVar2 = _fflush(*(FILE **)puVar1);
      local_142c = 0;
LAB_100003d74:
      if (*(long *)PTR____stack_chk_guard_100004010 == local_28) {
        return local_142c;
      }
                    /* WARNING: Subroutine does not return */
      ___stack_chk_fail(iVar2);
    }
    if (iVar3 != 100) {
      if (iVar3 == 0x74) {
        DAT_100008008 = _atoi(*(char **)PTR__optarg_100004078);
      }
      else {
        if (iVar3 != 0x77) {
          iVar2 = _fprintf(*(FILE **)PTR____stderrp_100004018,
                           "Usage: %s -t <timeout> -w <workdir> [-d]\n");
          local_142c = 1;
          goto LAB_100003d74;
        }
        local_1448 = _strdup(*(char **)PTR__optarg_100004078);
      }
      goto LAB_100003a48;
    }
    DAT_10000800c = 1;
  } while( true );
}


void ___stack_chk_fail(void)

{
                    /* WARNING: Could not recover jumptable at 0x000100003dc0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR____stack_chk_fail_100004008)();
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uint _alarm(uint param_1)

{
  uint uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003dcc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)PTR__alarm_100004028)(param_1);
  return uVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _atoi(char *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003dd8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__atoi_100004030)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _chdir(char *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003de4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__chdir_100004038)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _exit(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000100003df0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__exit_100004040)(param_1);
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _fflush(FILE *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003dfc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__fflush_100004048)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _fprintf(FILE *param_1,char *param_2,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003e08. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__fprintf_100004050)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _getchar(void)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003e14. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__getchar_100004058)();
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * _getcwd(char *param_1,size_t param_2)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003e20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR__getcwd_100004060)();
  return pcVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _getopt(int param_1,char *param_2,char *param_3)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003e2c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__getopt_100004068)(param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uid_t _getuid(void)

{
  uid_t uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003e38. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)PTR__getuid_100004070)();
  return uVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _printf(char *param_1,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003e44. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__printf_100004080)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _signal(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000100003e50. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__signal_100004088)(param_1);
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * _strdup(char *param_1)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003e5c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR__strdup_100004090)();
  return pcVar1;
}


/* WARNING: Control flow encountered bad instruction data */

void ___chkstk_darwin(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

