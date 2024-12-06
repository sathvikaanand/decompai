
void _timeout_handler(void)

{
  _puts("\n\nTimeout expired!");
                    /* WARNING: Subroutine does not return */
  _exit(1);
}


void _get_int(void)

{
  char acStack_428 [1024];
  long local_28;
  
  local_28 = *(long *)PTR____stack_chk_guard_100004010;
  _fgets(acStack_428,0x400,*(FILE **)PTR____stdinp_100004018);
  _strtol(acStack_428,(char **)0x0,0);
  if (*(long *)PTR____stack_chk_guard_100004010 == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


void _get_char(void)

{
  char local_28 [16];
  long local_18;
  
  local_18 = *(long *)PTR____stack_chk_guard_100004010;
  _fgets(local_28,0x10,*(FILE **)PTR____stdinp_100004018);
  if (*(long *)PTR____stack_chk_guard_100004010 == local_18) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail((long)local_28[0]);
}


void entry(void)

{
  undefined *puVar1;
  undefined *puVar2;
  ulong uVar3;
  long lVar4;
  undefined8 uVar5;
  undefined4 local_1470 [1024];
  char local_470 [1024];
  long local_70;
  
  (*(code *)PTR____chkstk_darwin_100004000)();
  local_70 = *(long *)PTR____stack_chk_guard_100004010;
  if (_timeout != 0) {
    _signal(0xe);
    _alarm(_timeout);
  }
  _puts("This service allows you to store integers in a table for future use.");
  _puts("Commands: Store (s), Read (r), Dump (d), Quit (q)");
  _bzero(local_1470,0x1000);
  _printf("Command: ");
  puVar2 = PTR____stdoutp_100004020;
  _fflush(*(FILE **)PTR____stdoutp_100004020);
  puVar1 = PTR____stdinp_100004018;
  _fgets(local_470,0x10,*(FILE **)PTR____stdinp_100004018);
  while (local_470[0] != -1) {
    switch((int)local_470[0]) {
    case 100:
      lVar4 = 0;
      do {
        _printf("%04d: %08d (0x%08x)\n");
        lVar4 = lVar4 + 1;
      } while (lVar4 != 0x400);
      break;
    case 0x65:
    case 0x66:
    case 0x67:
    case 0x68:
    case 0x69:
    case 0x6a:
    case 0x6b:
    case 0x6c:
    case 0x6d:
    case 0x6e:
    case 0x6f:
    case 0x70:
switchD_100003cc8_caseD_65:
      _printf("Unknown command %c\n");
      break;
    case 0x71:
      _puts("Quitting...");
      uVar5 = 0;
      goto LAB_100003d68;
    case 0x72:
      _printf("Index: ");
      _fflush(*(FILE **)puVar2);
      _fgets(local_470,0x400,*(FILE **)puVar1);
      _strtol(local_470,(char **)0x0,0);
      _printf("Value: %08d (0x%08x)\n");
      break;
    case 0x73:
      _printf("Index: ");
      _fflush(*(FILE **)puVar2);
      _fgets(local_470,0x400,*(FILE **)puVar1);
      uVar3 = _strtol(local_470,(char **)0x0,0);
      _printf("Value: ");
      _fflush(*(FILE **)puVar2);
      _fgets(local_470,0x400,*(FILE **)puVar1);
      lVar4 = _strtol(local_470,(char **)0x0,0);
      _printf(
             "Updating table value at index %04d with %08d (0x%08x): previous value was %08d (0x%08x)\n"
             );
      *(int *)((long)local_1470 +
              (-(uVar3 >> 0x1f & 1) & 0xfffffffc00000000 | (uVar3 & 0xffffffff) << 2)) = (int)lVar4;
      break;
    default:
      if (local_470[0] != 10) goto switchD_100003cc8_caseD_65;
    }
    _printf("Command: ");
    _fflush(*(FILE **)puVar2);
    _fgets(local_470,0x10,*(FILE **)puVar1);
  }
  uVar5 = 1;
LAB_100003d68:
  if (*(long *)PTR____stack_chk_guard_100004010 == local_70) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(uVar5);
}


void ___stack_chk_fail(void)

{
                    /* WARNING: Could not recover jumptable at 0x000100003dc4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR____stack_chk_fail_100004008)();
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uint _alarm(uint param_1)

{
  uint uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003dd0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)PTR__alarm_100004028)(param_1);
  return uVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _bzero(void *param_1,size_t param_2)

{
                    /* WARNING: Could not recover jumptable at 0x000100003ddc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__bzero_100004030)();
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _exit(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000100003de8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__exit_100004038)(param_1);
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _fflush(FILE *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003df4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__fflush_100004040)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * _fgets(char *param_1,int param_2,FILE *param_3)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003e00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR__fgets_100004048)(param_1,param_2);
  return pcVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _printf(char *param_1,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003e0c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__printf_100004050)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _puts(char *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003e18. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__puts_100004058)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _signal(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000100003e24. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__signal_100004060)(param_1);
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

long _strtol(char *param_1,char **param_2,int param_3)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003e30. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = (*(code *)PTR__strtol_100004068)(param_1,param_2,param_3);
  return lVar1;
}


/* WARNING: Control flow encountered bad instruction data */

void ___chkstk_darwin(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

