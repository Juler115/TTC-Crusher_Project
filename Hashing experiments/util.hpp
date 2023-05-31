#pragma once

#ifndef util_hpp
#define util_hpp

#ifdef _MSC_VER
#  include <intrin.h>
#  define __builtin_popcount __popcnt
#endif

#define pb push_back

typedef unsigned long long u64;
typedef unsigned long long u32;
typedef unsigned long long u16;
//typedef unsigned int u32;
//typedef unsigned short int u16;

// Moves:
//  Bit 0 - 3 piece to move
//  0 pawn, 1 knight, 2 bishop, 3 rook
//  Bit 16 - 31 from
//  Bit 32 - 45 to 


const u64 lookup[] = {
    0, 47,  1, 56, 48, 27,  2, 60,
    57, 49, 41, 37, 28, 16,  3, 61,
    54, 58, 35, 52, 50, 42, 21, 44,
    38, 32, 29, 23, 17, 11,  4, 62,
    46, 55, 26, 59, 40, 36, 15, 53,
    34, 51, 20, 43, 31, 22, 10, 45,
    25, 39, 14, 33, 19, 30,  9, 24,
    13, 18,  8, 12,  7,  6,  5, 63
};

const u64 debruijn = 0x03f79d71b4cb0a89;

struct board{
    // Bit 0-15 pawn, 16 - 31 knight, 32 - 45 bishop, 46 - 31 rook
    u64 white;
    u64 black;

    // Bit 0 white pawn direction (0 up, 1 down), 1 black pawn direction (0 up, 1 down)
    // Bit 2 - 4 white capture count (0-5), 5 - 7 black capture count (0-5)
    // Bit 10 - 15 (move count)
    u16 data;  

    u64 hash;
};

// Values for hashing stuff
const u64 pice_hash_code[8][16] = {
	{356941279769374233, 6278596199293129, 893701070657586346, 982847860504748494, 173784442745915570, 324788749203784878, 718742039975079357, 261639164493579068, 588663223959489950, 346437403246869517, 244147510563424958, 176270834820205920, 990034612292845273, 669886284432731041, 489642813106358661, 67703254585165849},
	{978127097863128693, 612566184984252794, 184593077528527951, 358550318779473483, 779849094190099652, 526681417471741503, 873810209132368669, 368631373979668593, 783363187386856035, 208915962233345141, 471531867317185772, 225375868035729377, 405252766442384536, 143874425196992837, 753045199752267647, 599869529689316911},

	{14226539783756942, 862411337941495149, 289941463855753600, 943077947665076455, 869144932265297520, 574221104184670180, 911516930928859500, 1100098760115234, 268658027445675320, 346266754059923614, 957366742512813557, 489951880591099673, 907432786561555556, 344705930643149571, 688092484961213381, 620552240162403852},
	{861949601355893664, 786337380552850811, 687322572332391924, 20028458668350823, 429469769554927557, 209746071325019307, 978534609166311793, 920474959784672105, 376324837753424338, 75223827688757450, 839097392679472883, 694882666285807441, 691506314201122402, 695698767416881635, 313771243721483435, 550776344990694969},

	{68310456893692338, 787308692653247940, 847388972324197901, 148449121604488709, 2443610072891901, 506131364320922538, 99413174531253527, 709539337131567516, 640574399296289129, 773713935369772782, 473258629492934433, 796761749583839550, 770241209525522592, 407306614325824088, 419417744662190472, 146433632190213886},
	{307521667628117170, 814170051336910359, 852027417620065725, 559043321488321549, 87774131868716586, 213642630599841520, 160523399458028345, 307501436816797748, 302410227368153940, 258535403673100064, 349277255792222035, 372184755438718932, 586669561483445632, 862438175976903583, 791202719736098824, 230060288208330793},

	{649063285676582717, 364432963239711977, 157441877995621538, 100337984405266527, 156658247256659904, 858689576259188188, 634617062455050389, 860251296761054709, 118711310212304969, 822679701590961229, 263882151610605281, 67813912464402187, 356158115779194151, 506620138084066016, 864543166506537717, 390351997364835512},
	{348891656990147670, 417434783435144901, 559923875601731021, 385222094552621119, 315148090263698842, 421501978119444662, 432264223784055835, 654851561091016849, 191864098603670521, 753127331594519878, 91000500069084801, 576603302705472119, 724502877172730768, 757204142447528089, 853599190640265463, 165828195738140246}
};

const u64 captures_h[2][16] = {
	{462148107432137548, 284824546541172138, 202579898397202955, 337292554029189848, 725905610594504664, 208013859866557914},
	{905489758722219211, 984014755861943524, 763283599141922028, 522412068624169829, 568522786209987534, 882780591808619425}
};

const u64 pawn_direction_h[2][16] =  {
	{475141295792892822, 346470658159402151},
	{54836294414406251, 407542032465882746}
};


#endif