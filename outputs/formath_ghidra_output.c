
/* WARNING: Function: __x86.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

int _init(EVP_PKEY_CTX *ctx)

{
  undefined *puVar1;
  
  puVar1 = PTR___gmon_start___000133d0;
  if (PTR___gmon_start___000133d0 != (undefined *)0x0) {
    puVar1 = (undefined *)(*(code *)PTR___gmon_start___000133d0)();
  }
  return (int)puVar1;
}


void FUN_00011030(void)

{
  (*(code *)PTR_00013384)();
  return;
}


void __cxa_finalize(void)

{
  (*(code *)PTR___cxa_finalize_000133cc)();
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_strcmp_00013388)();
  return iVar1;
}


void __libc_start_main(void)

{
  (*(code *)PTR___libc_start_main_000133b0)();
  return;
}


/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void processEntry _start(undefined4 param_1,undefined4 param_2)

{
  undefined auStack_4 [4];
  
  __libc_start_main(PTR_main_000133d4,param_2,&stack0x00000004,__libc_csu_init,__libc_csu_fini,
                    param_1,auStack_4);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


/* WARNING: This is an inlined function */

void __i686_get_pc_thunk_bx(void)

{
  return;
}


/* WARNING: This is an inlined function */

void __x86_get_pc_thunk_bx(void)

{
  return;
}


/* WARNING: Function: __x86.get_pc_thunk.dx replaced with injection: get_pc_thunk_dx */
/* WARNING: Removing unreachable block (ram,0x000112bb) */
/* WARNING: Removing unreachable block (ram,0x000112c5) */

void deregister_tm_clones(void)

{
  return;
}


/* WARNING: Function: __x86.get_pc_thunk.dx replaced with injection: get_pc_thunk_dx */
/* WARNING: Removing unreachable block (ram,0x0001130e) */
/* WARNING: Removing unreachable block (ram,0x00011318) */

void register_tm_clones(void)

{
  return;
}


/* WARNING: Function: __x86.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void __do_global_dtors_aux(void)

{
  if (completed_7623 == '\0') {
    if (PTR___cxa_finalize_000133cc != (undefined *)0x0) {
      __cxa_finalize(__dso_handle);
    }
    deregister_tm_clones();
    completed_7623 = '\x01';
  }
  return;
}


void frame_dummy(void)

{
  register_tm_clones();
  return;
}


/* WARNING: This is an inlined function */

void __x86_get_pc_thunk_dx(void)

{
  return;
}


/* WARNING: Unknown calling convention */

void timeout_handler(int signal)

{
  puts("\n\nTimeout expired!");
                    /* WARNING: Subroutine does not return */
  exit(1);
}


/* WARNING: Unknown calling convention */

int main(int argc,char **argv)

{
  char *pcVar1;
  int iVar2;
  size_t sVar3;
  uint uVar4;
  char local_4a0 [1023];
  char local_a1 [64];
  char acStack_61 [65];
  double local_20;
  undefined8 local_18;
  int *local_c;
  
  local_c = &argc;
  if (timeout != 0) {
    signal(0xe,timeout_handler);
    alarm(timeout);
  }
  printf("Execution id: %p\n",local_4a0);
  printf("Please provide a mathematical function: ");
  fflush(stdout);
  pcVar1 = fgets(acStack_61 + 1,0x40,stdin);
  if (pcVar1 == (char *)0x0) {
    perror("fgets");
    iVar2 = 1;
  }
  else {
    sVar3 = strlen(acStack_61 + 1);
    if (acStack_61[sVar3] == '\n') {
      sVar3 = strlen(acStack_61 + 1);
      acStack_61[sVar3] = '\0';
    }
    printf("Please provide a parameter: ");
    fflush(stdout);
    pcVar1 = fgets(local_a1 + 1,0x40,stdin);
    if (pcVar1 == (char *)0x0) {
      perror("fgets");
      iVar2 = 1;
    }
    else {
      sVar3 = strlen(local_a1 + 1);
      if (local_a1[sVar3] == '\n') {
        sVar3 = strlen(local_a1 + 1);
        local_a1[sVar3] = '\0';
      }
      local_20 = atof(local_a1 + 1);
      local_18 = 0.0;
      iVar2 = strcmp(acStack_61 + 1,"abs");
      if (iVar2 == 0) {
        uVar4 = (int)ROUND(local_20) >> 0x1f;
        local_18 = (double)(int)(((int)ROUND(local_20) ^ uVar4) - uVar4);
      }
      else {
        iVar2 = strcmp(acStack_61 + 1,"sinh");
        if (iVar2 == 0) {
          local_18 = sinh(local_20);
        }
        else {
          iVar2 = strcmp(acStack_61 + 1,"cosh");
          if (iVar2 == 0) {
            local_18 = cosh(local_20);
          }
          else {
            iVar2 = strcmp(acStack_61 + 1,"tanh");
            if (iVar2 != 0) {
              printf("Unknown function %s!\n",acStack_61 + 1);
              return 1;
            }
            local_18 = tanh(local_20);
          }
        }
      }
      snprintf(local_4a0,0x3ff,"The application of %s to %s returned %f\n",acStack_61 + 1,
               local_a1 + 1,(undefined4)local_18,local_18._4_4_);
      local_a1[0] = '\0';
      printf(local_4a0);
      iVar2 = 0;
    }
  }
  return iVar2;
}


/* WARNING: Function: __x86.get_pc_thunk.bp replaced with injection: get_pc_thunk.bp */

void __libc_csu_init(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  EVP_PKEY_CTX *in_stack_ffffffe4;
  
  _init(in_stack_ffffffe4);
  iVar1 = 0;
  do {
    (*(code *)(&__frame_dummy_init_array_entry)[iVar1])(param_1,param_2,param_3);
    iVar1 = iVar1 + 1;
  } while (iVar1 != 1);
  return;
}


void __libc_csu_fini(void)

{
  return;
}


/* WARNING: This is an inlined function */

void __x86_get_pc_thunk_bp(void)

{
  return;
}


/* WARNING: Function: __x86.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void _fini(void)

{
  return;
}


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* strcmp@@GLIBC_2.0 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */

void _ITM_deregisterTMCloneTable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int printf(char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* printf@@GLIBC_2.0 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fflush(FILE *__stream)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* fflush@@GLIBC_2.0 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * fgets(char *__s,int __n,FILE *__stream)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* fgets@@GLIBC_2.0 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__sighandler_t signal(int __sig,__sighandler_t __handler)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* signal@@GLIBC_2.0 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uint alarm(uint __seconds)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* alarm@@GLIBC_2.0 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */

void __cxa_finalize(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* __cxa_finalize@@GLIBC_2.1.3 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void perror(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* perror@@GLIBC_2.0 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int puts(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* puts@@GLIBC_2.0 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */

void __gmon_start__(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void exit(int __status)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* exit@@GLIBC_2.0 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* strlen@@GLIBC_2.0 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */

void __libc_start_main(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* __libc_start_main@@GLIBC_2.0 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* snprintf@@GLIBC_2.0 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

double tanh(double __x)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* tanh@@GLIBC_2.0 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

double cosh(double __x)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* cosh@@GLIBC_2.0 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

double atof(char *__nptr)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* atof@@GLIBC_2.0 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */

void _ITM_registerTMCloneTable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

double sinh(double __x)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* sinh@@GLIBC_2.0 */
  halt_baddata();
}

