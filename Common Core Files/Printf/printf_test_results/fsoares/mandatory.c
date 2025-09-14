#include "pf_utils.h"

void simple_test()
{
	TEST("no format", {
		test_printf_noarg("");
		test_printf_noarg("\x01\x02\a\v\b\f\r\n");
	})

	TEST("% format", {
		test_printf_noarg("%%");
		test_printf_noarg(" %%");
		test_printf_noarg("%%c");
		test_printf_noarg("%%%%%%");
		test_printf("%%%c", 'x');
	})
}

void test_c()
{
	TEST("c format", {
		test_printf("%c", 'x');
		test_printf(" %c", 'x');
		test_printf("%c ", 'x');
		test_printf("%c%c%c", 'a', '\t', 'b');
		test_printf("%cc%cc%c", 'a', '\t', 'b');
		test_printf("%cs%cs%c", 'c', 'b', 'a');
	})
}

void test_s()
{
	TEST("s format", {
		test_printf("%s", "");
		test_printf("%s", (char *)NULL);
		test_printf("%s", "some string with %s hehe");
		test_printf(" %s", "can it handle \t and \n?");
		test_printf("%sx", "{} al$#@@@^&$$^#^@@^$*((&");
		test_printf("%s%s%s", "And ", "some", "joined");
		test_printf("%ss%ss%ss", "And ", "some other", "joined");
	})
}

void test_p()
{
	TEST("p format", {
		test_printf("%p", "");
		test_printf("%p", NULL);
		test_printf("%p", (void *)-14523);
		test_printf("0x%p-", (void *)ULONG_MAX);
		test_printf("%pp%p%p", (void *)LONG_MAX + 423856, (void *)0, (void *)INT_MAX);
	})
}

void test_d()
{
	TEST("d format", {
		test_printf("%d", 0);
		test_printf("%d", -10);
		test_printf("%d", -200000);
		test_printf("%d", -6000023);
		test_printf("%d", 10);
		test_printf("%d", 10000);
		test_printf("%d", 100023);
		test_printf("%d", INT_MAX);
		test_printf("%d", INT_MIN);
		test_printf("dgs%dxx", 10);
		test_printf("%d%dd%d", 1, 2, -3);
	})
}

void test_i()
{
	TEST("i format", {
		test_printf("%i", 0);
		test_printf("%i", -10);
		test_printf("%i", -200000);
		test_printf("%i", -6000023);
		test_printf("%i", 10);
		test_printf("%i", 10000);
		test_printf("%i", 100023);
		test_printf("%i", INT_MAX);
		test_printf("%i", INT_MIN);
		test_printf("dgs%ixx", 10);
		test_printf("%i%ii%i", 1, 2, -3);
	})
}

void test_u()
{
	TEST("u format", {
		test_printf("%u", 0);
		test_printf("%u", -10);
		test_printf("%u", -200000);
		test_printf("%u", -6000023);
		test_printf("%u", 10);
		test_printf("%u", 10000);
		test_printf("%u", 100023);
		test_printf("%u", INT_MAX);
		test_printf("%u", INT_MIN);
		test_printf("%u", UINT_MAX);
		test_printf("dgs%uxx", 10);
		test_printf("%u%uu%u", 1, 2, -3);
	})
}

void test_x()
{
	TEST("x format", {
		test_printf("%x", 0);
		test_printf("%x", -10);
		test_printf("%x", -200000);
		test_printf("%x", -6000023);
		test_printf("%x", 10);
		test_printf("%x", 10000);
		test_printf("%x", 100023);
		test_printf("%x", 0xabcdef);
		test_printf("%x", 0x7fedcba1);
		test_printf("%x", INT_MAX);
		test_printf("%x", INT_MIN);
		test_printf("%x", UINT_MAX);
		test_printf("dgs%xxx", 10);
		test_printf("%x%xx%x", 1, 2, -3);
	})
}

void test_X()
{
	TEST("X format", {
		test_printf("%X", 0);
		test_printf("%X", -10);
		test_printf("%X", -200000);
		test_printf("%X", -6000023);
		test_printf("%X", 10);
		test_printf("%X", 10000);
		test_printf("%X", 100023);
		test_printf("%X", 0xabcdef);
		test_printf("%X", 0x7fedcba1);
		test_printf("%X", INT_MAX);
		test_printf("%X", INT_MIN);
		test_printf("%X", UINT_MAX);
		test_printf("dgs%Xxx", 10);
		test_printf("%X%Xx%X", 1, 2, -3);
	})
}

int main(int argn, char **argv)
{
	printf(YEL "Mandatory:" NC "\n");
	pf_setup_framework(argn, argv);

	simple_test();
	test_c();
	test_s();
	test_p();
	test_d();
	test_i();
	test_u();
	test_x();
	test_X();

	TEST("random", {
		// generated in python
				/* 2 */ test_printf_silent("%uQ%p>ONc{t|.0%ptgC3v\nA=\t%i59%sk%%Jd\n[$*Ir", 19214701, (void *)5306089950660973090, (void *)-5871255662291174690, -701758828, "z1C]2Se|!jRk9zI^=O)A8u8 GGFvg]9EBjFfRb2<=l J0qBq=qhG#(qzy");
		/* 3 */ test_printf_silent("Go5hQ %x%ub.!%cjs\t(vl %s?CEc%u\r,-/&\nl~", 667514534, -30203084, -91041382, "6\"X~+jq/Tsn#Y:&,G87\tF:a+&N1*K':7w'dXfE}\r\\\rBOEa@+-8P/2\n B%K`I2Ti=-p5I ,C'6&)vp'50H\"P@lUTffCHFX5`w?\"F", -395757532);
		/* 4 */ test_printf_silent("\\~\r%u%s`^\fW$A", -1916942132, "`\fzCsH?;\r!]/T1S7AU&lzQTlIt6BuwTDB!\fFqOH>8n-|");
		/* 5 */ test_printf_silent("^DV}%u;\"%sg %p{FC~!;%x>t1rp\th=%%7h'\"jH`%p\v4vNX]!%uHejp`5_%x%pJbI7:~ <.r", 1588113028, "\"!NR4Kf}%,[c7,-EJN{Wv/s9O77\n#Cy\f\v[\tJ%V6=vw7Celz=0ILkjk\rK];CY*b=){SV#(GEMah_&CoOx't)`", (void *)-153161188255580922, 1244406350, (void *)-5748794426477907742, 2092561961, 611515727, (void *)3315965131312832345);
		/* 6 */ test_printf_silent("86@9rB%sTt#4LyZ%XC8'~-My%%`(ge", "t\f&M*.D\n\f_$Ke8k9K[e", 305182435);
		/* 7 */ test_printf_silent("z5h7u9%%2\r%stCt0r2\v[.%xB]\t>yR4e%x,u=J(:)%ds\tg-%c}XPuA3okU8%p\t%c", ".Hi[;WE+m1[i@u'bqcZ}.0?vC6=$[^!:d5W|", -1745304603, -1896133546, 1545497509, -453276748, (void *)8656661929006200704, 1626257711);
		/* 8 */ test_printf_silent(";B9j%x\vP\\nqdo2|%c%xoEK>WK%%m_~i%%u\v%sN7w%xK\t%i`?)5{T+", 1227215092, 967982899, -1474484548, "A,DwA8:l^zJ@pn5k(\\MJr e\r}/V`N@2uq^,YSBnVGI'W{we@fk,Cr", 1488298467, -1614156881);
		/* 9 */ test_printf_silent("vh%u:2%d_^,6oc<6", -1001756025, -948337413);
		/* 10 */ test_printf_silent(":#'%X%ij j7~\nWq%iGz;%iz Sx cCil%pdtH;\"25", 1379949160, -1445405616, 1716252559, -991809831, (void *)1339921574215965901);
		/* 11 */ test_printf_silent("'%%Pvyt%d~d\nUys-j%c%%P\tI%%gZ%x6H5^k9", 245934335, 1196512685, 1018538667);
		/* 12 */ test_printf_silent("!%Xuy!9Np%sS}?G,?M]%iA", -964739701, "s=uO|`38\v-K)><}$8'#jsjF/#9QocM p\"poY1si4&,YA (OuC65U_dFF#\\u\"3gwq~V'NmH\ra*Glf\\]#zmN,a&jn+i\n!", -1524616131);
		/* 13 */ test_printf_silent("%i-F=J%cG%s2|?9%cbdS%iu;$OWnJn'%X%p\"Q^sb,ef-L%u*I_58J;o6%diP0Y{7\t+\">", -1371950339, -1957972792, "y29\vYG", 1169016533, 1170291438, 2000601528, (void *)2501521861643436048, -1075764983, 44855480);
		/* 14 */ test_printf_silent("7b6q%ch{i@c9k%s 45ePi^%%{c= %cel+iZ d5l%%uS9HzQK$v%c~c:+GHIG.", -1918128770, "(^Hde)F?R`-(km^Et-^waHf+I$NgQ45!S%Iq,I/aBxs95%yVb}P-@\tscxb{7b\v", 1087807458, 1584309308);
		/* 15 */ test_printf_silent("%%)64\f%p(wD", (void *)-3675771816192492709);
		/* 16 */ test_printf_silent("_}%uC\\%%d]q2b<%cv'w+v;[4\nW%i9\\%iQ~[Tr%%(Ol%d%X4%i\r%X/D$Z'~", -1668036168, -546697712, 507253981, 1364432793, 2055412827, -1974860998, -248554750, 578349549);
		/* 17 */ test_printf_silent(")%xe:G/%x%p!C|~;*%pGd\vCFcI['x%xZA a&{T8ju%%OjJr.\f%XPum\vdR &", 696638106, 79549259, (void *)4736198330294869351, (void *)-8647038423627180076, 1850482929, -102719943);
		/* 18 */ test_printf_silent("~9?kzQB%%%xJo#g3%x5IHN-e1%X0%Xh\fE\f", 733458504, 1924376899, 1423656395, -896252147);
		/* 19 */ test_printf_silent("1=4it%d\t}7Xz%cA<Km", -1920183075, 754689725);
		/* 20 */ test_printf_silent(" F;W%i:Qbs$St}0%iTkh%%6\n +q%d#Qy5bg-%%\v-&+DxH4\t_%u|U.\n\r%i8vEF\rHZP%u[SWal%XMd%c8", -1748001772, 6294085, 1766399072, 1758105801, 677637354, 1651171795, 1523871987, -1700921446);
		/* 21 */ test_printf_silent("%p[S4Oz|%X/\">Z6%p%ci\t&~+\n,L*%cld\r&Oe _9%X\t", (void *)8315241524851973439, 414305894, (void *)-5428826747232700845, -1952793752, -1480881795, -12151444);
		/* 22 */ test_printf_silent("7RW q$\t1}%%?U ;*%u%pyD&_\rxdS`%pV%uM.rq%d]/K;r5X %d,\r%Xs!", 105707953, (void *)-5880780520574306692, (void *)-4779640302082700556, -872260721, 2037929364, -1630656400, 2060258876);
		/* 23 */ test_printf_silent("1,10Y2^l%Xp+/%%%uQ", -1735684076, -1049647892);
		/* 24 */ test_printf_silent(")%s<D+N~!HL%cP }kb#Z/", "v+b)P 27x!Hd>M(plq\"Z>J", -1393004163);
		/* 25 */ test_printf_silent(">.\vz)dI$(T%XWX%d%ut&9]jlY%x++TojI%u\" G6\"H%Xq\vX #%s%X\t)ZH)RA%pM)R8uO", -26242248, -386649071, 1940089975, 753051220, -1911178597, 776533275, "lZ{I[QM(g[A\vc_Z!)ANNY'qjx0#z>5!OT{bh", 1312830616, (void *)3461332222820288542);
		/* 26 */ test_printf_silent("Ir\vn2)61%s \\w%xI-TML+hk,%X/gu~H}C>mH%X49[PsPH<%c\v%ug&}%sg\nKZ", "R*8?1T!gQEid)YKnL\r3$)\"<,\tE\"E\f|'rxZ\vv{WDh!\"1I$-4FOz=#]cBz2Ks'J\\U\f UOW\\$0|&J*T_w^e", 1554006499, 1067843471, 1270387454, 1059338376, -129382091, "$Ik01W\t.:k(D@C7<Dq5*,+NY=W!WbmW6HaY7\t\"+d/,|Typ~J^NK[\tizE@^ NMQo0sTmv&");
		/* 27 */ test_printf_silent("\v\n%ps{A79N}!+^%d&S{)\txb%uV$G0^ g-\t9%X%s%u*I& L", (void *)-7877523554709782453, 925122939, -205334823, -582156078, "&\f#F>od~=\t,NS$_)`m%)YKPNFqi\r2KsXNBAx\"R.u9=sK}TOyLu$\nHiMeYrfuwZ>#W0R", -1765777718);
		/* 28 */ test_printf_silent("=',%db%x\\^3%p|{GX4W", 381393330, -907116374, (void *)-3200450726292092592);
		/* 29 */ test_printf_silent("w\f%c|(FuGr3L%u> PXnS:U!d%d{Bx%x8;in%cY58_x%d:\n%%g\tl;  tw%dO", -379751929, -1052946687, 298432268, -565098609, -1641795207, 1896376023, -292415807);
		/* 30 */ test_printf_silent("g >pR%xlz+%dz\"A\rR\fc%d?%d<aLvr~%X2u%d", 1092302691, 547632495, -2129955688, -1136888187, -1327439555, -2016147411);
		/* 31 */ test_printf_silent("qj%u%s!8f%c%sJI\t%u3%pZ^%s:R\vL(Z'l%i.a:;", -976755942, "NpIcpQeI/4Lu[%1|owUl^Q1Is'u<T'sGYkZU'y=H0Z-m87Y|/^_Y7.^sVb6B~h,>pBA!bH*J7kT@9(^\t:s8tN9nJD+\f}pJ!Iay", -1780688255, "ta7?W{jfrV@$Od(Puzw9(qu%$dQ6BM68Y`\"\rqArS0\tF!mg:\fh)Zs/6Pd^", 451911709, (void *)-6751070574783025905, "~n}\\oD|.Vy}CBlM3$=,M", 775881807);
		/* 32 */ test_printf_silent("9:ANP%d u-0A%po\r%X%i", 1482411422, (void *)-720538904016281205, -2005008164, -66100698);
		/* 33 */ test_printf_silent("4v#A%XE}%d%sN%i<\"$zTd%xn%%2Q\f6QQ|7\fr", 125294533, 961854704, "v,tJzm", 42676808, -2025614480);
		/* 34 */ test_printf_silent("=%sv/7%s\nJ%i", "F.w&P+zJ}S$.eZ(r;b", "O9f%UgH\\NK2}_LG0\nS#2k4}CLxfiaFkSz PY;H7$UsksEQcs+y]R',KG", -544593404);
		/* 35 */ test_printf_silent("%%f:\\&}$4I$%pB`\\Y%pt%%[$[Z", (void *)-5287167351599350185, (void *)-4469326484783545719);
		/* 36 */ test_printf_silent("n4dA{S^\npL%Xf~Nw@;=,%siD4%xfQtf\nV?TU~%xwQ~I}6W", 1341384435, ",>daKHfjL3b!sOY:ZW7_%nE:4xI|r?QD'Rh5aUv_*A\\[Iy", -417851125, -2146388832);
		/* 37 */ test_printf_silent("ID\\efIm\nSi%uYzD/`k1{\vd%i1e76bZ", -587882359, 1388326191);
		/* 38 */ test_printf_silent("u#p7bwP9C1%it'fNlm%ph:=U1HnDW%id", 190441602, (void *)8134340875726182747, 262856240);
		/* 39 */ test_printf_silent("B+jk-%i2%cGd>x\"|", 1518138201, -632726922);
		/* 40 */ test_printf_silent("O,%XE%uz<r\t\\fkZ/g%%z", 744144974, -1102531966);
		/* 41 */ test_printf_silent(")@*?/%cCye{g#]%c>G%%+%if9,%d#|Iy`U]l%pH4s\"&&V\fEk%d.YyH%%] j9U%xBe_zs\nz([%i7k7-", 300998707, -1651658851, 2127925909, -1231069287, (void *)-4295948146950500520, 583540083, -1675201424, 1329936743);
		/* 42 */ test_printf_silent("ID[=A0|so%syv0*JXN%x%uYSfKk%cozlkC~", "D1Z}^\\]1yTGgZ=53o", 583963059, -696370958, 541408032);
		/* 43 */ test_printf_silent("\"WCuk\n%cz%cnPy<OwQ%de?I%dg\\}+%x\fu\\B be%x|UcGjMC<", 813129316, 431559470, -1756020805, -653834963, 343258737, 516072007);
		/* 44 */ test_printf_silent("YmA%d%p\n@jdG#`%iRE%pnY>:6%u%%J}X/EIud%u%xA_\r>T`T%dtCJ4rZ-A%c", -2120503144, (void *)-5810113375926153464, -385360955, (void *)5302564554331333950, 1159374685, 1767738000, 1237695263, -58794949, -1150617947);
		/* 45 */ test_printf_silent("[R[=.%pmno>y6*%%{z\n%x4g~>r]%sLgeXwT`i%X/\\IH%d|%cl$@3|Xy", (void *)1152730330268913749, -397959054, "ks/<_c", 1210028280, 316836529, -922472509);
		/* 46 */ test_printf_silent("&C%u6I%i%uI[Oj^*\t{#P%d\f\vNf'tL9%p\nL\tHqSKu\v+%d\rnTu7 (3\vd%XexN$2e.%XI6", -2037687706, -1948090111, 1775396033, 2019775464, (void *)-6692441150507605464, -2048257717, 137153388, 1503567936);
		/* 47 */ test_printf_silent("@I'.%xM ~pqq%x d`+ I\n%cKh&ei%p,I?AFg;", -953464939, 2046321373, 1717452717, (void *)-5226726411144936658);
		/* 48 */ test_printf_silent("~A%dVe059DNeV%i\n$ka4%s\\UnWs%c3-&5}\v\v\fQ", 1683883, 2023830586, "S*8d,wF1\t}\vyv\rPUz`4>7NWu\t3*(-E&l$l?;U'nBXgwo~*M?TygdB@7}=&Mx\tfG;]Ui%\fPVz]WyK%\f1,", -1532556622);
		/* 49 */ test_printf_silent("7F\t\"%%*(ea^/'R%x\\%iM%c%%\fJ%iVq]n(\r%u%s2\rf{*B6EuZ%up%d\f*", -492978569, -1415123849, 1100711977, 412989300, -447453234, ":lX2F0*nVoYt-`GZ>>#Xyl", 173509939, 229932175);
		/* 50 */ test_printf_silent("cr$Ac7K%ciqy`%ii{w \\e%dV9fVYiUO\n%u~*w\\jE{92%cGLC%c*\\)", -2075991798, -634555821, -687534116, 1681727189, 1294530980, -1017970404);
		/* 51 */ test_printf_silent("]a`jjefq5%dhZFSqtx%pu.%ukm8Ga\f%p)n>ms)>+k[%X&a`%%EB9/%pPEf\n#31>%p", 1559033907, (void *)1772061236471346123, -597074911, (void *)-5413856813782515707, 673444634, (void *)6946140876270822658, (void *)-4062411922927413708);
		/* 52 */ test_printf_silent("%%V%c KW]K\r%X\t7tp ,}o<@%xh%xsM%%Z^7%x3bO\n\tFgk%sS1%s|_6%s", 653543914, 1675623915, 116429255, -1221171015, -806852173, "K s^Ky5a{lWCi-kX!4e6=.E3w\f=%a[h[bNRCL1;x<", ";gx/0LA-lT]x^cvP]]|-T.=JrPTL.MAg`uN,B|h\\\tQo^I(.$er?_\\79Z1SkSfvd\v@\t-/g~+Gf$;U;Wf:*", "NUO2DA;xtx'zJ\nBLdt>");
		/* 53 */ test_printf_silent("%s8%pRVm%s>\\,Q.$%xFaYa.Y,g", "x5F.!\tF\\/Hn1J'PB(", (void *)-2729413515804426425, "[8x", 398154614);
		/* 54 */ test_printf_silent("&v\"G%%%xg0%iOH\n\t&c%u`|i[%pnggeq%x^%cOuFhBGZ%cH5VB2[}\f%dVOA6%%/q)hb4\r5\"h", 344427131, 3002722, -1083427292, (void *)6662571324530004158, -190183909, 1113035363, -2066014816, -1234649908);
		/* 55 */ test_printf_silent("|(im/f`n}g%c,=$uXi CC0%c62:\"T^/3Uv%s3?%i+ke?a", -637762259, 892046329, "_ 8ueFu1's}/TW$q~=wsiPbqTzgL{2sa?|7JEK&ql`>M1r-L9(@7#`7%l", -848858549);
		/* 56 */ test_printf_silent("Xn\\l%i%c *2S^c%c^O7\tf\ff5", -464460024, -1714738866, -1493974269);
		/* 57 */ test_printf_silent("v:\vVZB%d%%S/q&\f%c\n\r?%xg@S>", 865815691, 1178921000, -369537567);
		/* 58 */ test_printf_silent("{%uiB%d%u_]^,W", 705434774, -703855728, -2021587209);
		/* 59 */ test_printf_silent("'l%Xq\fU8o7~0\r7%%\n\r=Ge%i$wr9p,%sG7f.p5sJ%c:1qB%xBt[p\n*2%XUt79", -1121159825, -1342011141, "L%i5<b\f't=fy6`NS\n,waKR6!0le\n))XFnhs\n!CC&;FpObD%x#'/N1HV\":)?1+TfRznX\rHB;X0M?\f3\nURWBP}SD);<o\\'5", 2019509036, -1253318007, 2089347291);
		/* 60 */ test_printf_silent("@\">oE3/P%il%cnuq4%%\vF\"a%iU%cLS9\f%uV'.rgaAd*%sc%u", -1285302879, 315528513, -952941954, -505192063, 245895895, "jM", -284645748);
		/* 61 */ test_printf_silent("\"i9=Du@Jrs%cI\rG#j\r8GEg%u~\nm\t2:]^%%nk\t6}7%u\t\r\\.%u\t%%~XgY %c?d%dP[}h?^}%dRVGm", 651256258, -2087820562, -253849604, 245873360, 455473517, 1617069892, -459019211);
		/* 62 */ test_printf_silent("bc\tXC%p]\nK$%c@E4X8:{#w\v", (void *)4753944190644693771, -1574864785);
		/* 63 */ test_printf_silent("{lHQ!\tycr4%%UF<Y?%cK:bSw.q%X%s?%p>By\nCt%xlA\vG;Ju\"%XdA%s[.iK.?;a%X}$=>1", -1740326697, -341386233, "k%-", (void *)2468867967349833927, -2119205808, -1979745868, "IP': \\\ns/4!;e:bwQmz(", 483205103);
		/* 64 */ test_printf_silent("\fP%%65+6(+%Xy%x-Y`%X?%xA2\f|;}SP%X09Og*i:QI ", -736960546, -1043618802, 702395982, 1214617143, -652164948);
		/* 65 */ test_printf_silent("5o7h{l%iXa+Wj%s\"\"i@%%bZO", -1277332067, "pN72K:NsC9N$twq^c\rFxDS\"P~iR\fIEb[;A!~ga 6fbK|\vgE,%.foI+9f `{^+\rz~@LGSTU:");
		/* 66 */ test_printf_silent(" 9;6BFPL%s}rmTE:@V#%u\v`T4{2]U;\v%c&Rh", "0LQWX5[\\Cz{N^,ut\rL\n%)RkpQn(G<0yRpO7\\,Bwb2l(k+#X7JbDiEeu]) q_Y_B=n+9 eZ8dPtaZX,.a4%F!", 306044544, -95125186);
		/* 67 */ test_printf_silent("{$$9\\p_+2E%%um%xPD%p2%dRS,w%%Z,hX%dh%uH\vU\n:", 654693580, (void *)4618035690994086677, 1113024755, 1891103149, -1781185869);
		/* 68 */ test_printf_silent("|_%XXh%sLG\f%pJ&3`/lv%pV_)_BDwo%pGuU%% %Xh~Ssf|N)%d=8HD", 1545330628, "VNWI~$uQOIpG~pVw\"\r\t9t*SI^~O yNx FY}'\v$n7\fY]Of\"w3{!39[$m_jk($feQ6RZ%x9J", (void *)-6083957202634331237, (void *)5490504179645961751, (void *)-1012669262007046808, -1608377945, -2044427902);
		/* 69 */ test_printf_silent("%u`t>lzsxh)%p)%d\"mw62f%xL]2%sQ#|r\fk%u\v\\`hvN", -1458045036, (void *)-5391064996139460192, -322597063, -736577204, "(E^BGOE9!d6)k\r\\7+hjBG}IfaDyIMPxm+rw=Wx{w\v|-^fRc?\t%E?lN \r%KX7@D3+Q+~\fM8&}A", 1771267954);
		/* 70 */ test_printf_silent("*)X4ML8cq#%i)J1:WI\v#%x%i2W,u7%idC'F4`z|+", -1313391848, 1009708952, 1641410808, 512209460);
		/* 71 */ test_printf_silent("7\"%sq^%ut\v|?6Rl", "u\\&UCk\"S,VAw)7{ssbWu0#?S@\rcf5<$ !Q*F:!XVm\f8", -2136864940);
		/* 72 */ test_printf_silent("j=-\\3[%u>>ID8[X%p HG&)vb%p5l\n3.`&G\\", 1326413337, (void *)2716744911776441779, (void *)2877074315044690861);
		/* 73 */ test_printf_silent("aL\r.L_-PCX%xb`i !S%pox\f8=wT", 958661429, (void *)3977370667429497581);
		/* 74 */ test_printf_silent("z%u@T3%cTm%i Y%x&O%i%sdOTH8%d\rI%s, c9]2JE 5", -1818263576, 737559077, 224491921, 419647611, 1539115456, "9^Pih:R`\r\t>Qb\fYdN", -267124585, "5x.l5Os0|$*h='2IPOL\fcf");
		/* 75 */ test_printf_silent("nRH37Q!%%RfvK%%OFsdP%%_HWOWw-l%cKMF@xIp?%c~\n$\r\\<i(%uZbB:KnS\f{%sh:oew\tjthw", 807797922, -1282054356, -658989436, "y+9k{:-4o[n(J5Fv{aUZBR\"qhK;-1*7(UR}`@&ILgX0WSdSU=uG#c\nE'98_Nj\t;vI@\fr+\t_4a\t\"_T|ugE#C|zpe2dH");
		/* 76 */ test_printf_silent("FO!-,7GG7J%Xl3=i%p\t\n%u1Fbw\tXt%u!|>&hpl%d\rOUY%%\t>L?", -1183580584, (void *)-3570908958752575201, 1382443410, -1199492658, -1927035531);
		/* 77 */ test_printf_silent("8u6TiI&%cwjlIs_\v;X%dg5]3wrPOs%dr9]6Gi%s:\\\\%uZcP(d1M%sK]orzs%i<9Py%izJM Y<fFm%dQ(eb`5", 1749543459, 762459845, 658548721, "A^/H</>%6|~\ftHi8sr_B1q`\nj&ZWAxqHly{<pt3KK9D{\vE*31,h!O{{^wJY,:=9k;l!80\r-%ZCL:K9]T}4,4{\nx7v=\t-}u", -69278413, "Om\\GJ6?9xX\t#<jrV'>\vfS\"0y pjFQ>s]*@|OUy0\t8t^ADtQJ&5eG;J\\I\\`o+x4<?<GH7Q~L~n2.\\Fr,[9W=W(", 1086889463, 1993693358, 1547472743);
		/* 78 */ test_printf_silent("v`%%%ud6iD\rLQ%i7mSF\n,q< &%u&lj\n ,xV%%W@uSJOR_>%in%%j", 112060590, -1782832270, -1957238584, -626373422);
		/* 79 */ test_printf_silent("%XI)\v%iq\vMG H%XCG&#9\fO\f=%dn9lwM*1|%sam\r\fm%uip\nN<<HtH%iaUJ[rv%pF", 951036974, 693251007, 1657951644, -422909374, "/k\\okh2\"P^0TyK0bIL\fu\"SO%K\vb.86e^dO/ZgI0NxndOlO[\f1r|Y\"u5u+WNcY'\"7MTE4>e\"rvx", -1111540765, -207930629, (void *)-875312984603831344);
		/* 80 */ test_printf_silent("s{:%%%dPe(0s< %%lKSW0%dM%puthe1\t%c%p]+%u,4`3q\v", -1829464757, -949237566, (void *)-9010014330236554719, -954730773, (void *)-5914329204089003849, 1254246185);
		/* 81 */ test_printf_silent("3W|Q\"mF%i)GB%iLD%xF-rP%cZ\f<", 924820209, -391514160, -400615898, 118342915);
		/* 82 */ test_printf_silent("}dI2;%uFQ\f)?u+h4k%Xq*4n%c%ck1G{4n D", -827333736, -409789909, -1970023051, -1766295054);
		/* 83 */ test_printf_silent("!s\tTDT%st%X<V:%c\f&i:xk?r%%%pNKB-l%c$S7I%d!~r4SzwTU", "w-Z}", -751681585, 870490618, (void *)-3949003570053548699, -779837719, -1681168874);
		/* 84 */ test_printf_silent("%Xo#V'Im74%xCkD\"U\f;I9%x\fllCTW%s1QF+_dek^_", 1579674059, -926362181, 69504053, "FO'cd@7G!>\t~mv')a\vE'UV!=bDM'<hj/V,NS\nOs\\2XL{Q}W6d26d([E<M(7U#m\"\n^3gc#iyHEC");
		/* 85 */ test_printf_silent("\n p6d#4%Xs%pS\tD\rcho", 2010977781, (void *)1986273002694285126);
		/* 86 */ test_printf_silent("%uk%u#).:,%%E<Qj^0,QA@%Xe%xg`\fa%X=8%p;", 439215138, -439826017, 715525902, -698075717, -404018731, (void *)8214742158379506507);
		/* 87 */ test_printf_silent("LXy`Q-%X\\FI`R%X)dkj\v%pk8Qf\"e%iF>)'>T_%d,\n^{KyYt9L%xUqo^P%x0gF!=r", -1227320152, 1747152317, (void *)-5184336684993663688, 2125388429, 644735673, -1187773113, 1312963079);
		/* 88 */ test_printf_silent("CQJRX#%spG0.\tl_PZ%x%u&)G}-\"d%s4f9&I|0g%xQ", "!Y}e[!VU5g O`", 219581597, -1444436750, "Z\"!I!W\n&pd7~R4<r1!@EC6}7hHCxFvzC62nd8}obh{f-qO#chCQ;RAPu#Mxk]`a$H*td5'S:43{Xu{\\OQlGX[D", -94479905);
		/* 89 */ test_printf_silent("%ii,kN4'Vo%u%u08hQ8%X\\U^3N@*-%i4iD^,?re]", -787777379, -1075788850, -919002173, -2074658913, 830667126);
		/* 90 */ test_printf_silent("$Y_%d}z%i0Cbh&7,\v?m%i\n'e.\"?&", 526120558, 1569226120, 2052642822);
		/* 91 */ test_printf_silent("UK%X%%!Y](\nF@l%c%s._|*.)VEzX%dD 6D9S hn%i?/Ux", 720334760, -1256452132, "SEl&*3F\nP[}0daG\\B2&{9]$2ITqqB\f6n>O1( \\", 1143105910, 1040067616);
		/* 92 */ test_printf_silent("Ym\\:!t(/%s,x%XMSE\fA+E\v%c$%de\\0 tvbm%ukz#8JW<Be%st&&EUs #%duAjOYl;$33%iZ-%X:2p\f(!4%io\fWme|^", "iayCLKs,yll<YMf>f$K!tlTZ[|?m4iW,x", -1624353990, 335048879, 537584552, 1615283178, "d'Qr5.\fo*>4cgXzT|SdsBg*zy3Yt`j~{bE:}JKtc9+?v>_Gwf<#\v cX;\"ND2{a", 864184819, 1088055453, 1123178605, -1031313815);
		/* 93 */ test_printf_silent("jp}%cyk5:Hcu6\r%co@z", -784616679, -897411585);
		/* 94 */ test_printf_silent("vngH\tvy%x_%d9Y%XpS[%xw7uoK=d\r%XoY.#*O5>", -50324957, -1980929006, 1937935797, -1257761512, 233206474);
		/* 95 */ test_printf_silent("!PRlN S%Xp\v%s'Q\vsb/M%dR,B{mI9%s.V $R0(/h%pyo\\E(\f]}f%i#Rq%iYNU8a%X%c", 1064983287, ";KQ}.%%m$ {78Y\"\rJ..N[tN\rQ4q$\"\t3K^wlL \\2)Z\\>ReFQ6\tDvfkGSU8'15gloUFg<$T(%N=|X.^urr;~_wH", -1588937633, "f0Q\tP0OC*op5aIUkBsH+CN\r[DbaxP:&j14OE[bY79X:abIWr>DNDf<\vx6 aycrx7?5m&[DBAYg|6rkSU|AR\t+)qsNlDBC[", (void *)5633625149836750495, -526091834, 102072537, -549092362, -1457935942);
		/* 96 */ test_printf_silent("<D^V)%X%uAD/%ccY%p1A T5J\"k>_%x/)ZEfP%i?laG%iZzq/%%6 Y/t9Lz%c'G~b", -249715690, 1404089058, -272083604, (void *)-2530700182839917201, -113312577, -668216668, 966077466, -1558386040);
		/* 97 */ test_printf_silent("3j\v`&JXKs?%sco%%Dz%c<%c+vG7O%pi\t'|%uvE[b'nnyY%dVl<aO\f%d8T", "AC8\t&=%S<A&1{g))4\f&g*y\\[Nvmnv\\]'[921$W7\rMH#h!d`7>F%[D=", -1614301619, -1465315053, (void *)-1383741147243411395, -608027605, -47988450, -287636113);
		/* 98 */ test_printf_silent("\r9oa{4 J%xGK&8a.8qpA%px6%XwVIKXJ;%u%x<Sba%Xf", -800774270, (void *)2135337621337708473, -286172543, 1684531328, 276749967, -517179513);
		/* 99 */ test_printf_silent("lw)R\r/X%i|H=G%iE-ex9A=%pP,b,%XEi}1W3%%{]\"HN[%%8>@%X\n'%x?bdab'l", -652016272, 1635677554, (void *)-1192636120880990034, 554578948, 314443948, 1322715668);
		/* 100 */ test_printf_silent("p%iWG %u%s]7U\n%u$q,,zf}5@\\%ut~7@>%i\ty$tSr&RT\\%dzv\r']D0zmC", 484004538, -1563318127, "]C:\f| z~xYq\v\tq3mh`FMr^8hW2 ^Y\fL\nR\"i7G;hAd_otYS8W#21#keMSKv7\\9:4zfs4g.io\t)5!Q2gZxmpW\t\f[_C4rt", -1196197440, -1574529741, 1209716067, -505060577);
		/* 101 */ test_printf("(\rP85'gW%iL%sxL[0A~`\n%i5?|OJ%u-*", 55277012, "^%ivM6~$RW&)PI~(On#b0u\fDGK*MCO\f!_,$", -1633852067, -437685243);
	});
}