
void _timeout_handler(void)

{
  _puts("\n\nTimeout expired!");
                    /* WARNING: Subroutine does not return */
  _exit(1);
}


void entry(void)

{
  undefined auVar1 [16];
  undefined auVar2 [16];
  undefined auVar3 [16];
  undefined4 uVar4;
  undefined6 uVar5;
  undefined4 uVar6;
  undefined6 uVar7;
  undefined4 uVar8;
  undefined6 uVar9;
  undefined *puVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  undefined8 uVar14;
  char *extraout_x1;
  long lVar15;
  ulong uVar16;
  ulong uVar17;
  ulong uVar18;
  undefined8 *puVar19;
  char *pcVar20;
  byte bVar21;
  byte bVar22;
  byte bVar23;
  byte bVar24;
  byte bVar25;
  byte bVar26;
  byte bVar27;
  byte bVar28;
  byte bVar29;
  byte bVar30;
  byte bVar31;
  byte bVar32;
  byte bVar33;
  byte bVar34;
  byte bVar35;
  byte bVar36;
  byte bVar37;
  byte bVar41;
  byte bVar42;
  byte bVar43;
  byte bVar44;
  byte bVar45;
  byte bVar46;
  byte bVar47;
  byte bVar48;
  byte bVar49;
  byte bVar50;
  byte bVar51;
  byte bVar52;
  byte bVar53;
  byte bVar54;
  byte bVar55;
  undefined auVar38 [16];
  undefined auVar39 [16];
  undefined auVar40 [16];
  byte bVar56;
  byte bVar57;
  byte bVar58;
  byte bVar59;
  byte bVar60;
  byte bVar61;
  byte bVar62;
  byte bVar63;
  byte bVar64;
  byte bVar66;
  byte bVar67;
  byte bVar68;
  byte bVar69;
  byte bVar70;
  byte bVar71;
  undefined8 uVar65;
  byte bVar72;
  byte bVar73;
  byte bVar75;
  byte bVar76;
  byte bVar77;
  byte bVar78;
  byte bVar79;
  byte bVar80;
  undefined8 uVar74;
  byte bVar81;
  byte bVar82;
  byte bVar84;
  byte bVar85;
  byte bVar86;
  byte bVar87;
  byte bVar88;
  byte bVar89;
  undefined8 uVar83;
  byte bVar90;
  byte bVar91;
  byte bVar93;
  byte bVar94;
  byte bVar95;
  byte bVar96;
  byte bVar97;
  byte bVar98;
  undefined8 uVar92;
  byte bVar99;
  byte bVar100;
  byte bVar102;
  byte bVar103;
  byte bVar104;
  byte bVar105;
  byte bVar106;
  byte bVar107;
  undefined8 uVar101;
  byte bVar108;
  byte bVar109;
  byte bVar111;
  byte bVar112;
  byte bVar113;
  byte bVar114;
  byte bVar115;
  byte bVar116;
  undefined8 uVar110;
  byte bVar117;
  byte bVar118;
  byte bVar120;
  byte bVar121;
  byte bVar122;
  byte bVar123;
  byte bVar124;
  byte bVar125;
  undefined8 uVar119;
  byte bVar126;
  byte bVar127;
  byte bVar129;
  byte bVar130;
  byte bVar131;
  byte bVar132;
  byte bVar133;
  byte bVar134;
  undefined8 uVar128;
  byte bVar135;
  byte bVar136;
  byte bVar138;
  byte bVar139;
  byte bVar140;
  byte bVar141;
  byte bVar142;
  byte bVar143;
  undefined8 uVar137;
  byte bVar144;
  byte bVar145;
  byte bVar147;
  byte bVar148;
  byte bVar149;
  byte bVar150;
  byte bVar151;
  byte bVar152;
  undefined8 uVar146;
  byte bVar153;
  byte bVar154;
  byte bVar156;
  byte bVar157;
  byte bVar158;
  byte bVar159;
  byte bVar160;
  byte bVar161;
  undefined8 uVar155;
  byte bVar162;
  undefined8 uVar163;
  undefined8 uVar164;
  undefined8 uVar165;
  undefined8 uVar166;
  char acStack_1468 [4096];
  char local_468 [8];
  undefined8 auStack_460 [127];
  long local_68;
  
  iVar11 = (*(code *)PTR____chkstk_darwin_100004000)();
  puVar10 = PTR__optarg_100004078;
  pcVar20 = (char *)0x0;
  local_68 = *(long *)PTR____stack_chk_guard_100004010;
  while( true ) {
    while (iVar12 = _getopt(iVar11,extraout_x1,"t:w:d"), 0x73 < iVar12) {
      if (iVar12 == 0x74) {
        _timeout = _atoi(*(char **)puVar10);
      }
      else {
        if (iVar12 != 0x77) goto LAB_100003b44;
        pcVar20 = _strdup(*(char **)puVar10);
      }
    }
    if (iVar12 != 100) break;
    _debug = 1;
  }
  if (iVar12 == -1) {
    if (_timeout != 0) {
      _signal(0xe);
      _alarm(_timeout);
    }
    if (pcVar20 != (char *)0x0) {
      _chdir(pcVar20);
    }
    _getcwd(acStack_1468,0x1000);
    if (_debug != 0) {
      _getuid();
      _printf("Running service %s in %s as user %d...\n");
    }
    _printf(
           "Welcome to the checksum verifier service!\n    Your service ticket id is: %p\n    Please provide the data to verify: "
           );
    puVar10 = PTR____stdoutp_100004020;
    _fflush(*(FILE **)PTR____stdoutp_100004020);
    _i = 0;
    uVar13 = _getchar();
    while( true ) {
      _c = (char)uVar13;
      if ((uVar13 & 0xff) == 10) break;
      lVar15 = (long)(int)_i;
      local_468[lVar15] = _c;
      _i = _i + 1;
      local_468[lVar15 + 1] = '\0';
      uVar13 = _getchar();
    }
    _printf("Received a buffer of length %d\n");
    _fflush(*(FILE **)puVar10);
    _checksum = 0;
    uVar16 = (ulong)_i;
    if ((int)_i < 1) {
      _j = 0;
    }
    else {
      if (_i < 8) {
        uVar17 = 0;
        _checksum = 0;
LAB_100003d08:
        lVar15 = uVar16 - uVar17;
        pcVar20 = local_468 + uVar17;
        do {
          _checksum = _checksum ^ (int)*pcVar20;
          lVar15 = lVar15 + -1;
          pcVar20 = pcVar20 + 1;
        } while (lVar15 != 0);
      }
      else if (_i < 0x20) {
        _checksum = 0;
        uVar18 = 0;
LAB_100003ca4:
        uVar17 = uVar16 & 0xfffffff8;
        bVar21 = 0;
        bVar22 = 0;
        bVar23 = 0;
        bVar24 = 0;
        bVar25 = 0;
        bVar26 = 0;
        bVar27 = 0;
        bVar28 = 0;
        bVar29 = 0;
        bVar30 = 0;
        bVar31 = 0;
        bVar32 = 0;
        bVar33 = 0;
        bVar34 = 0;
        bVar35 = 0;
        bVar36 = 0;
        auVar38._4_12_ = SUB1612(ZEXT816(0),4);
        auVar38._0_4_ = _checksum;
        lVar15 = uVar18 - uVar17;
        pcVar20 = local_468 + uVar18;
        do {
          uVar14 = *(undefined8 *)pcVar20;
          bVar37 = (byte)uVar14;
          bVar41 = (byte)((ulong)uVar14 >> 8);
          bVar42 = (byte)((ulong)uVar14 >> 0x10);
          bVar43 = (byte)((ulong)uVar14 >> 0x18);
          bVar44 = (byte)((ulong)uVar14 >> 0x20);
          bVar45 = (byte)((ulong)uVar14 >> 0x28);
          bVar46 = (byte)((ulong)uVar14 >> 0x30);
          bVar47 = (byte)((ulong)uVar14 >> 0x38);
          bVar21 = bVar21 ^ bVar44;
          bVar22 = bVar22 ^ (char)bVar44 >> 7;
          bVar23 = bVar23 ^ (byte)((short)(char)bVar44 >> 0xf);
          bVar24 = bVar24 ^ (byte)((short)(char)bVar44 >> 0xf);
          bVar25 = bVar25 ^ bVar45;
          bVar26 = bVar26 ^ (char)bVar45 >> 7;
          bVar27 = bVar27 ^ (byte)((short)(char)bVar45 >> 0xf);
          bVar28 = bVar28 ^ (byte)((short)(char)bVar45 >> 0xf);
          bVar29 = bVar29 ^ bVar46;
          bVar30 = bVar30 ^ (char)bVar46 >> 7;
          bVar31 = bVar31 ^ (byte)((short)(char)bVar46 >> 0xf);
          bVar32 = bVar32 ^ (byte)((short)(char)bVar46 >> 0xf);
          bVar33 = bVar33 ^ bVar47;
          bVar34 = bVar34 ^ (char)bVar47 >> 7;
          bVar35 = bVar35 ^ (byte)((short)(char)bVar47 >> 0xf);
          bVar36 = bVar36 ^ (byte)((short)(char)bVar47 >> 0xf);
          auVar39[0] = auVar38[0] ^ bVar37;
          auVar39[1] = auVar38[1] ^ (char)bVar37 >> 7;
          auVar39[2] = auVar38[2] ^ (byte)((short)(char)bVar37 >> 0xf);
          auVar39[3] = auVar38[3] ^ (byte)((short)(char)bVar37 >> 0xf);
          auVar39[4] = auVar38[4] ^ bVar41;
          auVar39[5] = auVar38[5] ^ (char)bVar41 >> 7;
          auVar39[6] = auVar38[6] ^ (byte)((short)(char)bVar41 >> 0xf);
          auVar39[7] = auVar38[7] ^ (byte)((short)(char)bVar41 >> 0xf);
          auVar39[8] = auVar38[8] ^ bVar42;
          auVar39[9] = auVar38[9] ^ (char)bVar42 >> 7;
          auVar39[10] = auVar38[10] ^ (byte)((short)(char)bVar42 >> 0xf);
          auVar39[0xb] = auVar38[0xb] ^ (byte)((short)(char)bVar42 >> 0xf);
          auVar39[0xc] = auVar38[0xc] ^ bVar43;
          auVar39[0xd] = auVar38[0xd] ^ (char)bVar43 >> 7;
          auVar39[0xe] = auVar38[0xe] ^ (byte)((short)(char)bVar43 >> 0xf);
          auVar39[0xf] = auVar38[0xf] ^ (byte)((short)(char)bVar43 >> 0xf);
          lVar15 = lVar15 + 8;
          pcVar20 = pcVar20 + 8;
          auVar38 = auVar39;
        } while (lVar15 != 0);
        bVar21 = auVar39[0] ^ bVar21;
        bVar22 = auVar39[1] ^ bVar22;
        bVar23 = auVar39[2] ^ bVar23;
        bVar24 = auVar39[3] ^ bVar24;
        bVar25 = auVar39[4] ^ bVar25;
        bVar26 = auVar39[5] ^ bVar26;
        bVar27 = auVar39[6] ^ bVar27;
        bVar28 = auVar39[7] ^ bVar28;
        auVar1[1] = bVar22;
        auVar1[0] = bVar21;
        auVar1[2] = bVar23;
        auVar1[3] = bVar24;
        auVar1[4] = bVar25;
        auVar1[5] = bVar26;
        auVar1[6] = bVar27;
        auVar1[7] = bVar28;
        auVar1[8] = auVar39[8] ^ bVar29;
        auVar1[9] = auVar39[9] ^ bVar30;
        auVar1[10] = auVar39[10] ^ bVar31;
        auVar1[0xb] = auVar39[0xb] ^ bVar32;
        auVar1[0xc] = auVar39[0xc] ^ bVar33;
        auVar1[0xd] = auVar39[0xd] ^ bVar34;
        auVar1[0xe] = auVar39[0xe] ^ bVar35;
        auVar1[0xf] = auVar39[0xf] ^ bVar36;
        auVar2[1] = bVar22;
        auVar2[0] = bVar21;
        auVar2[2] = bVar23;
        auVar2[3] = bVar24;
        auVar2[4] = bVar25;
        auVar2[5] = bVar26;
        auVar2[6] = bVar27;
        auVar2[7] = bVar28;
        auVar2[8] = auVar39[8] ^ bVar29;
        auVar2[9] = auVar39[9] ^ bVar30;
        auVar2[10] = auVar39[10] ^ bVar31;
        auVar2[0xb] = auVar39[0xb] ^ bVar32;
        auVar2[0xc] = auVar39[0xc] ^ bVar33;
        auVar2[0xd] = auVar39[0xd] ^ bVar34;
        auVar2[0xe] = auVar39[0xe] ^ bVar35;
        auVar2[0xf] = auVar39[0xf] ^ bVar36;
        auVar40 = NEON_ext(auVar1,auVar2,8,1);
        _checksum = CONCAT13(bVar24 ^ auVar40[3],
                             CONCAT12(bVar23 ^ auVar40[2],
                                      CONCAT11(bVar22 ^ auVar40[1],bVar21 ^ auVar40[0]))) ^
                    CONCAT13(bVar28 ^ auVar40[7],
                             CONCAT12(bVar27 ^ auVar40[6],
                                      CONCAT11(bVar26 ^ auVar40[5],bVar25 ^ auVar40[4])));
        if (uVar17 != uVar16) goto LAB_100003d08;
      }
      else {
        bVar21 = 0;
        bVar22 = 0;
        bVar23 = 0;
        bVar24 = 0;
        bVar25 = 0;
        bVar26 = 0;
        bVar27 = 0;
        bVar28 = 0;
        bVar29 = 0;
        bVar30 = 0;
        bVar31 = 0;
        bVar32 = 0;
        bVar33 = 0;
        bVar34 = 0;
        bVar35 = 0;
        bVar36 = 0;
        uVar17 = uVar16 & 0xffffffe0;
        bVar37 = 0;
        bVar41 = 0;
        bVar42 = 0;
        bVar43 = 0;
        bVar44 = 0;
        bVar45 = 0;
        bVar46 = 0;
        bVar47 = 0;
        bVar48 = 0;
        bVar49 = 0;
        bVar50 = 0;
        bVar51 = 0;
        bVar52 = 0;
        bVar53 = 0;
        bVar54 = 0;
        bVar55 = 0;
        puVar19 = auStack_460 + 1;
        uVar74 = 0;
        uVar83 = 0;
        uVar14 = 0;
        uVar65 = 0;
        uVar110 = 0;
        uVar119 = 0;
        uVar92 = 0;
        uVar101 = 0;
        uVar128 = 0;
        uVar137 = 0;
        uVar146 = 0;
        uVar155 = 0;
        uVar18 = uVar17;
        do {
          uVar164 = puVar19[-1];
          uVar163 = puVar19[-2];
          uVar166 = puVar19[1];
          uVar165 = *puVar19;
          bVar91 = (byte)uVar163;
          bVar94 = (byte)((ulong)uVar163 >> 8);
          bVar97 = (byte)((ulong)uVar163 >> 0x10);
          bVar100 = (byte)((ulong)uVar163 >> 0x18);
          bVar103 = (byte)((ulong)uVar163 >> 0x20);
          bVar107 = (byte)((ulong)uVar163 >> 0x28);
          bVar113 = (byte)((ulong)uVar163 >> 0x30);
          bVar117 = (byte)((ulong)uVar163 >> 0x38);
          uVar4 = CONCAT13((char)bVar94 >> 7,CONCAT12(bVar94,(short)(char)bVar91));
          uVar5 = CONCAT15((char)bVar97 >> 7,CONCAT14(bVar97,uVar4));
          uVar6 = CONCAT13((char)bVar107 >> 7,CONCAT12(bVar107,(short)(char)bVar103));
          uVar7 = CONCAT15((char)bVar113 >> 7,CONCAT14(bVar113,uVar6));
          bVar122 = (byte)((short)(char)bVar103 >> 0xf);
          bVar123 = (byte)((int)uVar6 >> 0x1f);
          bVar124 = (byte)((int6)uVar7 >> 0x2f);
          bVar126 = (byte)((long)CONCAT17((char)bVar117 >> 7,CONCAT16(bVar117,uVar7)) >> 0x3f);
          bVar77 = (byte)uVar164;
          bVar81 = (byte)((ulong)uVar164 >> 8);
          bVar86 = (byte)((ulong)uVar164 >> 0x10);
          bVar90 = (byte)((ulong)uVar164 >> 0x18);
          bVar59 = (byte)((ulong)uVar164 >> 0x20);
          bVar63 = (byte)((ulong)uVar164 >> 0x28);
          bVar68 = (byte)((ulong)uVar164 >> 0x30);
          bVar72 = (byte)((ulong)uVar164 >> 0x38);
          bVar112 = (byte)uVar165;
          bVar115 = (byte)((ulong)uVar165 >> 8);
          bVar120 = (byte)((ulong)uVar165 >> 0x10);
          bVar125 = (byte)((ulong)uVar165 >> 0x18);
          bVar105 = (byte)((ulong)uVar165 >> 0x20);
          bVar109 = (byte)((ulong)uVar165 >> 0x28);
          bVar114 = (byte)((ulong)uVar165 >> 0x30);
          bVar118 = (byte)((ulong)uVar165 >> 0x38);
          uVar6 = CONCAT13((char)bVar115 >> 7,CONCAT12(bVar115,(short)(char)bVar112));
          uVar7 = CONCAT15((char)bVar120 >> 7,CONCAT14(bVar120,uVar6));
          uVar8 = CONCAT13((char)bVar109 >> 7,CONCAT12(bVar109,(short)(char)bVar105));
          uVar9 = CONCAT15((char)bVar114 >> 7,CONCAT14(bVar114,uVar8));
          bVar95 = (byte)((short)(char)bVar105 >> 0xf);
          bVar99 = (byte)((int)uVar8 >> 0x1f);
          bVar104 = (byte)((int6)uVar9 >> 0x2f);
          bVar108 = (byte)((long)CONCAT17((char)bVar118 >> 7,CONCAT16(bVar118,uVar9)) >> 0x3f);
          bVar93 = (byte)uVar166;
          bVar96 = (byte)((ulong)uVar166 >> 8);
          bVar98 = (byte)((ulong)uVar166 >> 0x10);
          bVar102 = (byte)((ulong)uVar166 >> 0x18);
          bVar106 = (byte)((ulong)uVar166 >> 0x20);
          bVar111 = (byte)((ulong)uVar166 >> 0x28);
          bVar116 = (byte)((ulong)uVar166 >> 0x30);
          bVar121 = (byte)((ulong)uVar166 >> 0x38);
          bVar56 = (byte)uVar14 ^ bVar59;
          bVar57 = (byte)((ulong)uVar14 >> 8) ^ (char)bVar59 >> 7;
          bVar58 = (byte)((ulong)uVar14 >> 0x10) ^ (byte)((short)(char)bVar59 >> 0xf);
          bVar59 = (byte)((ulong)uVar14 >> 0x18) ^ (byte)((short)(char)bVar59 >> 0xf);
          bVar60 = (byte)((ulong)uVar14 >> 0x20) ^ bVar63;
          bVar61 = (byte)((ulong)uVar14 >> 0x28) ^ (char)bVar63 >> 7;
          bVar62 = (byte)((ulong)uVar14 >> 0x30) ^ (byte)((short)(char)bVar63 >> 0xf);
          bVar63 = (byte)((ulong)uVar14 >> 0x38) ^ (byte)((short)(char)bVar63 >> 0xf);
          uVar14 = CONCAT17(bVar63,CONCAT16(bVar62,CONCAT15(bVar61,CONCAT14(bVar60,CONCAT13(bVar59,
                                                  CONCAT12(bVar58,CONCAT11(bVar57,bVar56)))))));
          bVar64 = (byte)uVar65 ^ bVar68;
          bVar66 = (byte)((ulong)uVar65 >> 8) ^ (char)bVar68 >> 7;
          bVar67 = (byte)((ulong)uVar65 >> 0x10) ^ (byte)((short)(char)bVar68 >> 0xf);
          bVar68 = (byte)((ulong)uVar65 >> 0x18) ^ (byte)((short)(char)bVar68 >> 0xf);
          bVar69 = (byte)((ulong)uVar65 >> 0x20) ^ bVar72;
          bVar70 = (byte)((ulong)uVar65 >> 0x28) ^ (char)bVar72 >> 7;
          bVar71 = (byte)((ulong)uVar65 >> 0x30) ^ (byte)((short)(char)bVar72 >> 0xf);
          bVar72 = (byte)((ulong)uVar65 >> 0x38) ^ (byte)((short)(char)bVar72 >> 0xf);
          uVar65 = CONCAT17(bVar72,CONCAT16(bVar71,CONCAT15(bVar70,CONCAT14(bVar69,CONCAT13(bVar68,
                                                  CONCAT12(bVar67,CONCAT11(bVar66,bVar64)))))));
          bVar73 = (byte)uVar74 ^ bVar77;
          bVar75 = (byte)((ulong)uVar74 >> 8) ^ (char)bVar77 >> 7;
          bVar76 = (byte)((ulong)uVar74 >> 0x10) ^ (byte)((short)(char)bVar77 >> 0xf);
          bVar77 = (byte)((ulong)uVar74 >> 0x18) ^ (byte)((short)(char)bVar77 >> 0xf);
          bVar78 = (byte)((ulong)uVar74 >> 0x20) ^ bVar81;
          bVar79 = (byte)((ulong)uVar74 >> 0x28) ^ (char)bVar81 >> 7;
          bVar80 = (byte)((ulong)uVar74 >> 0x30) ^ (byte)((short)(char)bVar81 >> 0xf);
          bVar81 = (byte)((ulong)uVar74 >> 0x38) ^ (byte)((short)(char)bVar81 >> 0xf);
          uVar74 = CONCAT17(bVar81,CONCAT16(bVar80,CONCAT15(bVar79,CONCAT14(bVar78,CONCAT13(bVar77,
                                                  CONCAT12(bVar76,CONCAT11(bVar75,bVar73)))))));
          bVar82 = (byte)uVar83 ^ bVar86;
          bVar84 = (byte)((ulong)uVar83 >> 8) ^ (char)bVar86 >> 7;
          bVar85 = (byte)((ulong)uVar83 >> 0x10) ^ (byte)((short)(char)bVar86 >> 0xf);
          bVar86 = (byte)((ulong)uVar83 >> 0x18) ^ (byte)((short)(char)bVar86 >> 0xf);
          bVar87 = (byte)((ulong)uVar83 >> 0x20) ^ bVar90;
          bVar88 = (byte)((ulong)uVar83 >> 0x28) ^ (char)bVar90 >> 7;
          bVar89 = (byte)((ulong)uVar83 >> 0x30) ^ (byte)((short)(char)bVar90 >> 0xf);
          bVar90 = (byte)((ulong)uVar83 >> 0x38) ^ (byte)((short)(char)bVar90 >> 0xf);
          uVar83 = CONCAT17(bVar90,CONCAT16(bVar89,CONCAT15(bVar88,CONCAT14(bVar87,CONCAT13(bVar86,
                                                  CONCAT12(bVar85,CONCAT11(bVar84,bVar82)))))));
          bVar37 = bVar37 ^ bVar103;
          bVar41 = bVar41 ^ (char)bVar103 >> 7;
          bVar42 = bVar42 ^ bVar122;
          bVar43 = bVar43 ^ bVar122;
          bVar44 = bVar44 ^ bVar107;
          bVar45 = bVar45 ^ (char)bVar107 >> 7;
          bVar46 = bVar46 ^ bVar123;
          bVar47 = bVar47 ^ bVar123;
          bVar48 = bVar48 ^ bVar113;
          bVar49 = bVar49 ^ (char)bVar113 >> 7;
          bVar50 = bVar50 ^ bVar124;
          bVar51 = bVar51 ^ bVar124;
          bVar52 = bVar52 ^ bVar117;
          bVar53 = bVar53 ^ (char)bVar117 >> 7;
          bVar54 = bVar54 ^ bVar126;
          bVar55 = bVar55 ^ bVar126;
          bVar21 = bVar21 ^ bVar91;
          bVar22 = bVar22 ^ (char)bVar91 >> 7;
          bVar91 = (byte)((short)(char)bVar91 >> 0xf);
          bVar23 = bVar23 ^ bVar91;
          bVar24 = bVar24 ^ bVar91;
          bVar25 = bVar25 ^ bVar94;
          bVar26 = bVar26 ^ (char)bVar94 >> 7;
          bVar91 = (byte)((int)uVar4 >> 0x1f);
          bVar27 = bVar27 ^ bVar91;
          bVar28 = bVar28 ^ bVar91;
          bVar29 = bVar29 ^ bVar97;
          bVar30 = bVar30 ^ (char)bVar97 >> 7;
          bVar91 = (byte)((int6)uVar5 >> 0x2f);
          bVar31 = bVar31 ^ bVar91;
          bVar32 = bVar32 ^ bVar91;
          bVar33 = bVar33 ^ bVar100;
          bVar34 = bVar34 ^ (char)bVar100 >> 7;
          bVar91 = (byte)((long)CONCAT17((char)bVar100 >> 7,CONCAT16(bVar100,uVar5)) >> 0x3f);
          bVar35 = bVar35 ^ bVar91;
          bVar36 = bVar36 ^ bVar91;
          bVar145 = (byte)uVar146 ^ bVar106;
          bVar147 = (byte)((ulong)uVar146 >> 8) ^ (char)bVar106 >> 7;
          bVar148 = (byte)((ulong)uVar146 >> 0x10) ^ (byte)((short)(char)bVar106 >> 0xf);
          bVar149 = (byte)((ulong)uVar146 >> 0x18) ^ (byte)((short)(char)bVar106 >> 0xf);
          bVar150 = (byte)((ulong)uVar146 >> 0x20) ^ bVar111;
          bVar151 = (byte)((ulong)uVar146 >> 0x28) ^ (char)bVar111 >> 7;
          bVar152 = (byte)((ulong)uVar146 >> 0x30) ^ (byte)((short)(char)bVar111 >> 0xf);
          bVar153 = (byte)((ulong)uVar146 >> 0x38) ^ (byte)((short)(char)bVar111 >> 0xf);
          uVar146 = CONCAT17(bVar153,CONCAT16(bVar152,CONCAT15(bVar151,CONCAT14(bVar150,CONCAT13(
                                                  bVar149,CONCAT12(bVar148,CONCAT11(bVar147,bVar145)
                                                                  ))))));
          bVar154 = (byte)uVar155 ^ bVar116;
          bVar156 = (byte)((ulong)uVar155 >> 8) ^ (char)bVar116 >> 7;
          bVar157 = (byte)((ulong)uVar155 >> 0x10) ^ (byte)((short)(char)bVar116 >> 0xf);
          bVar158 = (byte)((ulong)uVar155 >> 0x18) ^ (byte)((short)(char)bVar116 >> 0xf);
          bVar159 = (byte)((ulong)uVar155 >> 0x20) ^ bVar121;
          bVar160 = (byte)((ulong)uVar155 >> 0x28) ^ (char)bVar121 >> 7;
          bVar161 = (byte)((ulong)uVar155 >> 0x30) ^ (byte)((short)(char)bVar121 >> 0xf);
          bVar162 = (byte)((ulong)uVar155 >> 0x38) ^ (byte)((short)(char)bVar121 >> 0xf);
          uVar155 = CONCAT17(bVar162,CONCAT16(bVar161,CONCAT15(bVar160,CONCAT14(bVar159,CONCAT13(
                                                  bVar158,CONCAT12(bVar157,CONCAT11(bVar156,bVar154)
                                                                  ))))));
          bVar127 = (byte)uVar128 ^ bVar93;
          bVar129 = (byte)((ulong)uVar128 >> 8) ^ (char)bVar93 >> 7;
          bVar130 = (byte)((ulong)uVar128 >> 0x10) ^ (byte)((short)(char)bVar93 >> 0xf);
          bVar131 = (byte)((ulong)uVar128 >> 0x18) ^ (byte)((short)(char)bVar93 >> 0xf);
          bVar132 = (byte)((ulong)uVar128 >> 0x20) ^ bVar96;
          bVar133 = (byte)((ulong)uVar128 >> 0x28) ^ (char)bVar96 >> 7;
          bVar134 = (byte)((ulong)uVar128 >> 0x30) ^ (byte)((short)(char)bVar96 >> 0xf);
          bVar135 = (byte)((ulong)uVar128 >> 0x38) ^ (byte)((short)(char)bVar96 >> 0xf);
          uVar128 = CONCAT17(bVar135,CONCAT16(bVar134,CONCAT15(bVar133,CONCAT14(bVar132,CONCAT13(
                                                  bVar131,CONCAT12(bVar130,CONCAT11(bVar129,bVar127)
                                                                  ))))));
          bVar136 = (byte)uVar137 ^ bVar98;
          bVar138 = (byte)((ulong)uVar137 >> 8) ^ (char)bVar98 >> 7;
          bVar139 = (byte)((ulong)uVar137 >> 0x10) ^ (byte)((short)(char)bVar98 >> 0xf);
          bVar140 = (byte)((ulong)uVar137 >> 0x18) ^ (byte)((short)(char)bVar98 >> 0xf);
          bVar141 = (byte)((ulong)uVar137 >> 0x20) ^ bVar102;
          bVar142 = (byte)((ulong)uVar137 >> 0x28) ^ (char)bVar102 >> 7;
          bVar143 = (byte)((ulong)uVar137 >> 0x30) ^ (byte)((short)(char)bVar102 >> 0xf);
          bVar144 = (byte)((ulong)uVar137 >> 0x38) ^ (byte)((short)(char)bVar102 >> 0xf);
          uVar137 = CONCAT17(bVar144,CONCAT16(bVar143,CONCAT15(bVar142,CONCAT14(bVar141,CONCAT13(
                                                  bVar140,CONCAT12(bVar139,CONCAT11(bVar138,bVar136)
                                                                  ))))));
          bVar91 = (byte)uVar92 ^ bVar105;
          bVar93 = (byte)((ulong)uVar92 >> 8) ^ (char)bVar105 >> 7;
          bVar94 = (byte)((ulong)uVar92 >> 0x10) ^ bVar95;
          bVar95 = (byte)((ulong)uVar92 >> 0x18) ^ bVar95;
          bVar96 = (byte)((ulong)uVar92 >> 0x20) ^ bVar109;
          bVar97 = (byte)((ulong)uVar92 >> 0x28) ^ (char)bVar109 >> 7;
          bVar98 = (byte)((ulong)uVar92 >> 0x30) ^ bVar99;
          bVar99 = (byte)((ulong)uVar92 >> 0x38) ^ bVar99;
          uVar92 = CONCAT17(bVar99,CONCAT16(bVar98,CONCAT15(bVar97,CONCAT14(bVar96,CONCAT13(bVar95,
                                                  CONCAT12(bVar94,CONCAT11(bVar93,bVar91)))))));
          bVar100 = (byte)uVar101 ^ bVar114;
          bVar102 = (byte)((ulong)uVar101 >> 8) ^ (char)bVar114 >> 7;
          bVar103 = (byte)((ulong)uVar101 >> 0x10) ^ bVar104;
          bVar104 = (byte)((ulong)uVar101 >> 0x18) ^ bVar104;
          bVar105 = (byte)((ulong)uVar101 >> 0x20) ^ bVar118;
          bVar106 = (byte)((ulong)uVar101 >> 0x28) ^ (char)bVar118 >> 7;
          bVar107 = (byte)((ulong)uVar101 >> 0x30) ^ bVar108;
          bVar108 = (byte)((ulong)uVar101 >> 0x38) ^ bVar108;
          uVar101 = CONCAT17(bVar108,CONCAT16(bVar107,CONCAT15(bVar106,CONCAT14(bVar105,CONCAT13(
                                                  bVar104,CONCAT12(bVar103,CONCAT11(bVar102,bVar100)
                                                                  ))))));
          bVar109 = (byte)uVar110 ^ bVar112;
          bVar111 = (byte)((ulong)uVar110 >> 8) ^ (char)bVar112 >> 7;
          bVar113 = (byte)((short)(char)bVar112 >> 0xf);
          bVar112 = (byte)((ulong)uVar110 >> 0x10) ^ bVar113;
          bVar113 = (byte)((ulong)uVar110 >> 0x18) ^ bVar113;
          bVar114 = (byte)((ulong)uVar110 >> 0x20) ^ bVar115;
          bVar115 = (byte)((ulong)uVar110 >> 0x28) ^ (char)bVar115 >> 7;
          bVar117 = (byte)((int)uVar6 >> 0x1f);
          bVar116 = (byte)((ulong)uVar110 >> 0x30) ^ bVar117;
          bVar117 = (byte)((ulong)uVar110 >> 0x38) ^ bVar117;
          uVar110 = CONCAT17(bVar117,CONCAT16(bVar116,CONCAT15(bVar115,CONCAT14(bVar114,CONCAT13(
                                                  bVar113,CONCAT12(bVar112,CONCAT11(bVar111,bVar109)
                                                                  ))))));
          bVar118 = (byte)uVar119 ^ bVar120;
          bVar120 = (byte)((ulong)uVar119 >> 8) ^ (char)bVar120 >> 7;
          bVar122 = (byte)((int6)uVar7 >> 0x2f);
          bVar121 = (byte)((ulong)uVar119 >> 0x10) ^ bVar122;
          bVar122 = (byte)((ulong)uVar119 >> 0x18) ^ bVar122;
          bVar123 = (byte)((ulong)uVar119 >> 0x20) ^ bVar125;
          bVar124 = (byte)((ulong)uVar119 >> 0x28) ^ (char)bVar125 >> 7;
          bVar126 = (byte)((long)CONCAT17((char)bVar125 >> 7,CONCAT16(bVar125,uVar7)) >> 0x3f);
          bVar125 = (byte)((ulong)uVar119 >> 0x30) ^ bVar126;
          bVar126 = (byte)((ulong)uVar119 >> 0x38) ^ bVar126;
          uVar119 = CONCAT17(bVar126,CONCAT16(bVar125,CONCAT15(bVar124,CONCAT14(bVar123,CONCAT13(
                                                  bVar122,CONCAT12(bVar121,CONCAT11(bVar120,bVar118)
                                                                  ))))));
          puVar19 = puVar19 + 4;
          uVar18 = uVar18 - 0x20;
        } while (uVar18 != 0);
        bVar21 = bVar109 ^ bVar21 | bVar127 ^ bVar73 | bVar91 | bVar37 | bVar145 ^ bVar56;
        bVar22 = bVar111 ^ bVar22 | bVar129 ^ bVar75 | bVar93 | bVar41 | bVar147 ^ bVar57;
        bVar23 = bVar112 ^ bVar23 | bVar130 ^ bVar76 | bVar94 | bVar42 | bVar148 ^ bVar58;
        bVar24 = bVar113 ^ bVar24 | bVar131 ^ bVar77 | bVar95 | bVar43 | bVar149 ^ bVar59;
        bVar25 = bVar114 ^ bVar25 | bVar132 ^ bVar78 | bVar96 | bVar44 | bVar150 ^ bVar60;
        bVar26 = bVar115 ^ bVar26 | bVar133 ^ bVar79 | bVar97 | bVar45 | bVar151 ^ bVar61;
        bVar27 = bVar116 ^ bVar27 | bVar134 ^ bVar80 | bVar98 | bVar46 | bVar152 ^ bVar62;
        bVar28 = bVar117 ^ bVar28 | bVar135 ^ bVar81 | bVar99 | bVar47 | bVar153 ^ bVar63;
        bVar29 = bVar118 ^ bVar29 | bVar136 ^ bVar82 | bVar100 | bVar48 | bVar154 ^ bVar64;
        bVar30 = bVar120 ^ bVar30 | bVar138 ^ bVar84 | bVar102 | bVar49 | bVar156 ^ bVar66;
        bVar31 = bVar121 ^ bVar31 | bVar139 ^ bVar85 | bVar103 | bVar50 | bVar157 ^ bVar67;
        bVar32 = bVar122 ^ bVar32 | bVar140 ^ bVar86 | bVar104 | bVar51 | bVar158 ^ bVar68;
        bVar33 = bVar123 ^ bVar33 | bVar141 ^ bVar87 | bVar105 | bVar52 | bVar159 ^ bVar69;
        bVar34 = bVar124 ^ bVar34 | bVar142 ^ bVar88 | bVar106 | bVar53 | bVar160 ^ bVar70;
        bVar35 = bVar125 ^ bVar35 | bVar143 ^ bVar89 | bVar107 | bVar54 | bVar161 ^ bVar71;
        bVar36 = bVar126 ^ bVar36 | bVar144 ^ bVar90 | bVar108 | bVar55 | bVar162 ^ bVar72;
        auVar40[1] = bVar22;
        auVar40[0] = bVar21;
        auVar40[2] = bVar23;
        auVar40[3] = bVar24;
        auVar40[4] = bVar25;
        auVar40[5] = bVar26;
        auVar40[6] = bVar27;
        auVar40[7] = bVar28;
        auVar40[8] = bVar29;
        auVar40[9] = bVar30;
        auVar40[10] = bVar31;
        auVar40[0xb] = bVar32;
        auVar40[0xc] = bVar33;
        auVar40[0xd] = bVar34;
        auVar40[0xe] = bVar35;
        auVar40[0xf] = bVar36;
        auVar3[1] = bVar22;
        auVar3[0] = bVar21;
        auVar3[2] = bVar23;
        auVar3[3] = bVar24;
        auVar3[4] = bVar25;
        auVar3[5] = bVar26;
        auVar3[6] = bVar27;
        auVar3[7] = bVar28;
        auVar3[8] = bVar29;
        auVar3[9] = bVar30;
        auVar3[10] = bVar31;
        auVar3[0xb] = bVar32;
        auVar3[0xc] = bVar33;
        auVar3[0xd] = bVar34;
        auVar3[0xe] = bVar35;
        auVar3[0xf] = bVar36;
        auVar40 = NEON_ext(auVar40,auVar3,8,1);
        _checksum = CONCAT13(bVar24 ^ auVar40[3],
                             CONCAT12(bVar23 ^ auVar40[2],
                                      CONCAT11(bVar22 ^ auVar40[1],bVar21 ^ auVar40[0]))) ^
                    CONCAT13(bVar28 ^ auVar40[7],
                             CONCAT12(bVar27 ^ auVar40[6],
                                      CONCAT11(bVar26 ^ auVar40[5],bVar25 ^ auVar40[4])));
        if (uVar17 != uVar16) {
          uVar18 = uVar17;
          if ((_i & 0x18) == 0) goto LAB_100003d08;
          goto LAB_100003ca4;
        }
      }
      _j = _i;
      if (_checksum != 0) {
        _puts("Checksum failed! Exiting now...");
        _fflush(*(FILE **)puVar10);
                    /* WARNING: Subroutine does not return */
        _exit(1);
      }
    }
    _puts("Checksum is correct!");
    _fflush(*(FILE **)puVar10);
    uVar14 = 0;
    goto LAB_100003d54;
  }
LAB_100003b44:
  _fprintf(*(FILE **)PTR____stderrp_100004018,"Usage: %s -t <timeout> -w <workdir> [-d]\n");
  uVar14 = 1;
LAB_100003d54:
  if (*(long *)PTR____stack_chk_guard_100004010 == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(uVar14);
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

