ainclude <stdio.h>
#include <string.h>
#include <math.h>

#define TRUE	 1
#define FALSE	 0
#define BAD_VAL	-1
#define NULL	 0

#define STEWARD		0
#define ADMIN		1
#define STREETWISE	2
#define BROKER		3
#define LIAISON		4

#define HIGH		0
#define MIDDLE		1
#define LOW		2

#define MAJOR		0
#define MINOR		1
#define INCIDENTAL	2

int passenger[11][3][2] = { {{0, 0}, {0, 0}, {0, 0}},	/* 0 */
			    {{0, 0}, {1, 2}, {2, 6}},
			    {{1, 1}, {1, 0}, {2, 0}},	/* 2 */
			    {{2, 2}, {2, 1}, {2, 0}},
			    {{2, 1}, {2, 1}, {3, 1}},	/* 4 */
			    {{2, 1}, {3, 2}, {3, 1}},
			    {{3, 2}, {3, 2}, {3, 0}},	/* 6 */
			    {{3, 2}, {3, 1}, {3, 0}},
			    {{3, 1}, {3, 1}, {4, 0}},	/* 8 */
			    {{3, 1}, {3, 0}, {5, 0}},
			    {{3, 0}, {4, 0}, {6, 0}} };	/* A */

int lots[11][3][2] = { {{0, 0}, {0, 0}, {0, 0}},	/* 0 */
		       {{1,-4}, {1,-4}, {0, 0}},
		       {{1,-2}, {1,-1}, {0, 0}},	/* 2 */
		       {{1,-1}, {1, 0}, {0, 0}},
		       {{1, 0}, {1, 1}, {0, 0}},	/* 4 */
		       {{1, 1}, {1, 2}, {0, 0}},
		       {{1, 2}, {1, 3}, {1,-3}},	/* 6 */
		       {{1, 3}, {1, 4}, {1,-3}},
		       {{1, 4}, {1, 5}, {1,-2}},	/* 8 */
		       {{1, 5}, {1, 6}, {1,-2}},
		       {{1, 6}, {1, 7}, {1, 0}} };	/* A */

int goods[6][11][3] = {{{ 0, 11, 66},
			{ 0, 11, 66},
			{ 0, 41, 66},
			{ 0, 41, 66},
			{ 0, 41, 66},
			{ 1, 41, 66},
			{ 1, 41, 66},
			{ 2, 11, 66},
			{ 3, 11, 66},
			{ 3, 11, 66},
			{ 4, 11, 66}},

		       {{ 0, 11, 66},
			{ 0, 11, 66},
			{ 0, 11, 66},
			{ 0, 11, 66},
			{ 1, 11, 66},
			{ 1, 11, 66},
			{ 2, 11, 66},
			{ 3, 11, 66},
			{ 3, 11, 66},
			{ 3, 11, 66},
			{ 4, 11, 66}},

		       {{ 0, 11, 36},
			{ 0, 11, 36},
			{ 0, 11, 36},
			{ 0, 11, 36},
			{ 0, 11, 36},
			{ 1, 11, 36},
			{ 2, 11, 66},
			{ 2, 11, 66},
			{ 3, 11, 66},
			{ 3, 11, 66},
			{ 4, 11, 66}},

		       {{ 0, 11, 66},
			{ 0, 11, 66},
			{ 0, 11, 66},
			{ 0, 11, 66},
			{ 0, 11, 66},
			{ 1, 11, 66},
			{ 2, 11, 66},
			{ 2, 11, 66},
			{ 3, 11, 66},
			{ 3, 11, 66},
			{ 4, 11, 66}},

		       {{ 0, 11, 66},
			{ 0, 11, 66},
			{ 1, 11, 66},
			{ 1, 11, 66},
			{ 2, 11, 66},
			{ 2, 11, 66},
			{ 2, 11, 66},
			{ 2, 11, 66},
			{ 3, 11, 66},
			{ 3, 11, 66},
			{ 4, 11, 66}},

		       {{ 0, 11, 66},
			{ 0, 11, 66},
			{ 0, 11, 66},
			{ 3, 11, 66},
			{ 1, 11, 66},
			{ 1, 11, 66},
			{ 1, 11, 66},
			{ 2, 11, 66},
			{ 3, 11, 66},
			{ 3, 11, 66},
			{ 4, 11, 66}}};

char *product[5][36] =  {{ "Ferrous Metal Ore    ",	/* 11 */
			   "Ferrous Metal Ore    ",
			   "Ferrous Metal Ore    ",
			   "Non-metal Ore        ",
			   "Non-metal Ore        ",
			   "Radioactive Ore      ",
			   "Radioactive Ore      ",	/* 21 */
			   "Non-ferrous Ore      ",
			   "Non-ferrous Ore      ",
			   "Raw Crystals         ",
			   "Raw Crystals         ",
			   "Raw Crystals         ",
			   "Raw Precious Gems    ",	/* 31 */
			   "Nitrogen Compounds   ",
			   "Nitrogen Compounds   ",
			   "Raw Hydrocarbons     ",
			   "Raw Hydrocarbons     ",
			   "Raw Hydrocarbons     ",
			   "Plants (wood)        ",	/* 41 */
			   "Plants (wood)        ",
			   "Plants (bales)       ",
			   "Plants (fibers)      ",
			   "Plants (herbs)       ",
			   "Wild Plants (living) ",
			   "Food Plants (living) ",	/* 51 */
			   "Food Plants (living) ",
			   "Food Plants (living) ",
			   "Food Plants (living) ",
			   "Animals (living)     ",
			   "Animals (living)     ",
			   "Livestock (living)   ",	/* 61 */
			   "Livestock (living)   ",
			   "Livestock (living)   ",
			   "Livestock (living)   ",
			   "Rare Plants (living) ",
			   "Rare Animals (living)" },

			 { "Iron                 ",	/* 11 */
			   "Steel                ",
			   "Steel                ",
			   "Steel                ",
			   "Aluminum             ",
			   "Aluminum             ",
			   "Copper               ",	/* 21 */
			   "Tin                  ",
			   "Zinc                 ",
			   "Special Alloys       ",
			   "Gold                 ",
			   "Silver               ",
			   "Precious Metals      ",	/* 31 */
			   "Non-metals           ",
			   "Crystals             ",
			   "Radioactives         ",
			   "Rare Earths          ",
			   "Isotopes             ",
			   "Grain                ",	/* 41 */
			   "Grain                ",
			   "Vegatables           ",
			   "Fruit                ",
			   "Meat                 ",
			   "Herbs                ",
			   "Plant Compounds      ",	/* 51 */
			   "Animal Compounds     ",
			   "Petrochemicals       ",
			   "Petrochemicals       ",
			   "Textiles             ",
			   "Explosives           ",
			   "Polymers             ",	/* 61 */
			   "Polymers             ",
			   "Fertilizers          ",
			   "Plants (lumber)      ",
			   "Plants (paper)       ",
			   "Plants (paper)       " },

			 { "Pharmaceuticals      ",	/* 11 */
			   "Pharmaceuticals      ",
			   "Preserved Foods      ",
			   "Spices               ",
			   "Spices               ",
			   "Gourmet Foods        ",
			   "Flavored Water       ",	/* 21 */
			   "Alcoholic Beverages  ",
			   "Alcoholic Beverages  ",
			   "Consumable Milks     ",
			   "Consumable Nectars   ",
			   "Consumable Syrups    ",
			   "Consumable Teas      ",	/* 31 */
			   "Exotic Fluids        ",
			   "Aromatics            ",
			   "Aromatics            ",
			   "Disposables          ",
			   "Disposables          ",
			   "Clothing             ",	/* 41 */
			   "Clothing             ",
			   "Protective Wear      ",
			   "Weapons              ",
			   "Weapons              ",
			   "Weapons              ",
			   "Metal Parts          ",	/* 51 */
			   "Electronic Parts     ",
			   "High Tech Parts      ",
			   "Tools                ",
			   "Tools                ",
			   "Vehicles             ",
			   "Entertainment Equip. ",	/* 61 */
			   "Computers            ",
			   "Robots               ",
			   "Robots               ",
			   "Appliances           ",
			   "Furniture            " },

			 { "Writings (paper)     ",	/* 11 */
			   "Writings (data)      ",
			   "2D Still Pictures    ",
			   "2D Still Pictures    ",
			   "Computer Software    ",
			   "Computer Software    ",
			   "Robotic Software     ",	/* 21 */
			   "Robotic Software     ",
			   "Starship Software    ",
			   "Starship Software    ",
			   "3D Still Pictures    ",
			   "3D Still Pictures    ",
			   "Sculpture            ",	/* 31 */
			   "Paintings            ",
			   "Exotic Artforms      ",
			   "Audio Recordings     ",
			   "2D Video Recordings  ",
			   "3D Video Recordings  ",
			   "Raw Data (paper)     ",	/* 41 */
			   "Raw Data (data)      ",
			   "Raw Data (data)      ",
			   "Currency (valuables) ",
			   "Currency (valuables) ",
			   "Currency (paper)     ",
			   "Currency (paper)     ",	/* 51 */
			   "Currency (paper)     ",
			   "Currency (paper)     ",
			   "Records (paper)      ",
			   "Records (paper)      ",
			   "Records (paper)      ",
			   "Records (data)       ",	/* 61 */
			   "Records (data)       ",
			   "Records (data)       ",
			   "Records (data)       ",
			   "Records (data)       ",
			   "Records (data)       " },

			 { "New Natural Resources",	/* 11 */
			   "New Process Resources",
			   "New Mfd Goods        ",
			   "New Mfd Goods        ",
			   "New Information      ",
			   "New Information      ",
			   "Uniques              ",	/* 21 */
			   "Uniques              ",
			   "Uniques              ",
			   "Uniques              ",
			   "Uniques              ",
			   "Uniques              ",
			   "Uniques              ",	/* 31 */
			   "Uniques              ",
			   "Antiques             ",
			   "Antiques             ",
			   "Antiques             ",
			   "Antiques             ",
			   "Antiques             ",	/* 41 */
			   "Antiques             ",
			   "Original Information ",
			   "Original Information ",
			   "Original Information ",
			   "Original Information ",
			   "Original Information ",	/* 51 */
			   "Original Information ",
			   "Original Information ",
			   "Fad Information      ",
			   "Fad Information      ",
			   "Fad Information      ",
			   "Fad Mfd Goods        ",	/* 61 */
			   "Fad Mfd Goods        ",
			   "Prototype Mfd Goods  ",
			   "Prototype Mfd Goods  ",
			   "Prototype Mfd Goods  ",
			   "Prototype Mfd Goods  " }};

char *goods_name[5] = { "Natural Resources  ",
			"Processed Resources",
			"Manufactured Goods ",
			"Information        ",
			"Novelties          " };

char *skill_name[5] = { "Steward", "Admin", "Streetwise",
			"Broker", "Liaison" };

int barren=0, trade_table[6], goods_dm[6], code_cost_mod;

/* Begin NON-STANDARD MT cost modifiers */
int cost_mult[5] = {40, 70, 100, 110, 200};
/* End NON-STANDARD MT cost modifiers */

main(argc, argv)
int argc;
char *argv[];
{
  int skill[5];
  int star_port, w_size, w_gov, w_law, src_pop, dst_pop, src_TL, dst_TL;
  int amber_zone, red_zone, flag, i, dm;
  int hi_psg, mid_psg, lo_psg;
  int major_freight, minor_freight, inc_freight;
  int major_cargo, minor_cargo, inc_cargo;
  int catagory, roll, entry, top, bottom, cost, specific;
  char str[81], uwp[80];
  FILE *fd;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s [outfile]\n", argv[0]);
    exit(-1);
   }

  fd = fopen(argv[1], "w");
  if (fd == NULL) {
    fprintf(stderr, "%s: Cannot open '%s' for output\n", argv[0], argv[1]);
    exit(-1);
   }

  flag = TRUE;
  while(flag) {
    printf("Enter UWP of source world: ");
    scanf("%s", uwp);
    if (strlen(uwp) != 9) {
      printf("UWP format: ABCDEFG-H\n");
      printf("  A = Starport\n");
      printf("  B = World Size\n");
      printf("  C = Atmosphere\n");
      printf("  D = Hydrosphere\n");
      printf("  E = Population\n");
      printf("  F = Government\n");
      printf("  G = Law Level\n");
      printf("  H = Tech Level\n");
     }
    else
      flag = FALSE;
   }
  star_port = cvt_hex(uwp[0]);
  w_size = cvt_hex(uwp[1]);
  src_pop = cvt_hex(uwp[4]);
  w_gov = cvt_hex(uwp[5]);
  w_law = cvt_hex(uwp[6]);
  src_TL = cvt_hex(uwp[8]);

  printf("Enter buyer's following skill levels (if no skill, enter 0):\n");
  for (i=0; i<5; i++) {
    flag = TRUE;
    while (flag) {
      printf("%s: ", skill_name[i]);
      scanf("%d", &skill[i]);
      fflush(stdout);
      if ((skill[i] < 0) || (skill[i] > 10))
	printf("Skill range = 0-10\n");
      else
	flag = FALSE;
     } /* while */
   } /* for */

  printf("Enter pop. of dest. world: ");
  scanf("%s", str);
  dst_pop = cvt_hex(str[0]);
  fflush(stdout);
  printf("Enter TL of dest. world: ");
  scanf("%s", str);
  dst_TL = cvt_hex(str[0]);
  fflush(stdout);

  flag = TRUE;
  while (flag) {
    printf("Is dest. world Amber Zone? [y/n] ");
    scanf("%s", str);
    amber_zone = yes_or_no(str[0]);
    if (amber_zone == BAD_VAL)
      printf("Enter 'y' or 'n'\n");
    else
      flag = FALSE;
   }

  flag = TRUE;
  while (flag) {
    printf("Is dest. world Red Zone? [y/n] ");
    scanf("%s", str);
    red_zone = yes_or_no(str[0]);
    if (red_zone == BAD_VAL)
      printf("Enter 'y' or 'n'\n");
    else
      flag = FALSE;
   }
  fflush(stdin);
  get_trade_codes();

/*--- OK, we've got all of the neccessary input, now generate passengers ---*/

  /*--- first, high passage ---*/
  dm = skill[STEWARD];
  if ((dst_pop <= 0) && (dst_pop <=4)) dm -= 3;
  if (dst_pop <=8) dm += 1;
  dm += src_TL - dst_TL;
  if (red_zone) dm -= 12;
  if (amber_zone) dm -= 6;
  hi_psg = 0;
  for (i=0; i<passenger[w_size][HIGH][0]; i++)
    hi_psg += random(6);
  if (w_size != 1) {
    for (i=0; i<passenger[w_size][HIGH][1]; i++)
      hi_psg -= random(6);
   }
  else
    hi_psg -= passenger[w_size][HIGH][1];
  hi_psg += dm;
  if (hi_psg < 0) hi_psg = 0;

  if (!red_zone) {
    /*--- second, middle passage ---*/
    dm = skill[ADMIN];
    if ((dst_pop <= 0) && (dst_pop <=4)) dm -= 3;
    if (dst_pop <=8) dm += 1;
    dm += src_TL - dst_TL;
    if (amber_zone) dm -= 6;
    mid_psg = 0;
    for (i=0; i<passenger[w_size][MIDDLE][0]; i++)
      mid_psg += random(6);
    if (w_size != 1) {
      for (i=0; i<passenger[w_size][MIDDLE][1]; i++)
        mid_psg -= random(6);
     }
    else
      mid_psg -= passenger[w_size][MIDDLE][1];
    if (mid_psg < 0) mid_psg = 0;

    /*--- last, low passage ---*/
    dm = skill[STREETWISE];
    if ((dst_pop <= 0) && (dst_pop <=4)) dm -= 3;
    if (dst_pop <=8) dm += 1;
    dm += src_TL - dst_TL;
    if (amber_zone) dm -= 6;
    lo_psg = 0;
    for (i=0; i<passenger[w_size][LOW][0]; i++)
      lo_psg += random(6);
    if (w_size != 1) {
      for (i=0; i<passenger[w_size][LOW][1]; i++)
        lo_psg -= random(6);
     }
    else
      lo_psg -= passenger[w_size][LOW][1];
    if (lo_psg < 0) lo_psg = 0;
   }

  fprintf(fd, "Available Passengers:\n");
  fprintf(fd, "  Hi Psg. = %d, Mid Psg. = %d, Lo Psg. = %d\n",
		hi_psg, mid_psg, lo_psg);

/*--- next, generate the freight list ---*/
  major_freight = 0;
  minor_freight = 0;
  inc_freight = 0;
  dm = 0;
  if ((dst_pop <= 0) && (dst_pop <=4)) dm -= 3;
  if (dst_pop <=8) dm += 1;
  dm += src_TL - dst_TL;
  if (red_zone)
    fprintf(fd, "RED ZONE dst.: No Freight\n");
  else {
    if (!amber_zone) {
      for (i=0; i<lots[src_pop][MAJOR][0]; i++)
        major_freight += random(6);
      major_freight += lots[src_pop][MAJOR][1];
      major_freight += dm;
     } /* if */

    for (i=0; i<lots[src_pop][MINOR][0]; i++)
      minor_freight += random(6);
    minor_freight += lots[src_pop][MINOR][1];
    minor_freight += dm + skill[LIAISON];

    for (i=0; i<lots[src_pop][INCIDENTAL][0]; i++)
      inc_freight += random(6);
    inc_freight += lots[src_pop][INCIDENTAL][1];
    inc_freight += dm;
   }

  if (major_freight > 0) {
    fprintf(fd, "Major Freight:\n");
    for (i=0; i<major_freight; i++)
      fprintf(fd, "  Lot #%2d: %2d tons\n", i+1, random(6)*10);
   }
  if (minor_freight > 0) {
    fprintf(fd, "Minor Freight:\n");
    for (i=0; i<minor_freight; i++)
      fprintf(fd, "  Lot #%2d: %2d tons\n", i+1, random(6)*5);
   }
  if (inc_freight > 0) {
    fprintf(fd, "Incidental Freight:\n");
    for (i=0; i<inc_freight; i++)
      fprintf(fd, "  Lot #%2d: %2d tons\n", i+1, random(6));
   }

/*--- now, generate the cargo list ---*/
  major_cargo = 0;
  minor_cargo = 0;
  inc_cargo = 0;
  dm = 0;
  if ((dst_pop <= 0) && (dst_pop <=4)) dm -= 3;
  if (dst_pop <=8) dm += 1;
  dm += src_TL - dst_TL;
  if (red_zone)
    fprintf(fd, "RED ZONE dst.: No Freight\n");
  else {
    if (!amber_zone) {
      for (i=0; i<lots[src_pop][MAJOR][0]; i++)
        major_cargo += random(6);
      major_cargo += lots[src_pop][MAJOR][1];
      major_cargo += dm;
     } /* if */

    for (i=0; i<lots[src_pop][MINOR][0]; i++)
      minor_cargo += random(6);
    minor_cargo += lots[src_pop][MINOR][1];
    minor_cargo += dm + skill[LIAISON];

    for (i=0; i<lots[src_pop][INCIDENTAL][0]; i++)
      inc_cargo += random(6);
    inc_cargo += lots[src_pop][INCIDENTAL][1];
    inc_cargo += dm;
   }
  for (i=0; i<6; i++)
    goods_dm[i] = 0;
  if (w_gov > 8)
    for (i=0; i<6; i++)
      goods_dm[i]++;
  if (w_law > 8)
    for (i=0; i<6; i++)
      goods_dm[i]++;
  if (src_pop > 8) {
    goods_dm[1]++;
    goods_dm[2]++;
    goods_dm[5]++;
   }
  if (barren) {
    goods_dm[2] -= 5;
    goods_dm[3] -= 5;
    goods_dm[5] -= 7;
   }
  for (i=5; i>=0; i--)
    if (trade_table[i])
      catagory = i;
  dm = goods_dm[catagory];

  if (major_cargo > 0) {
    fprintf(fd, "Major Cargo:\n");
    for (i=0; i<major_cargo; i++) {
      fprintf(fd, "  Lot #%2d: %2d tons - ", i+1, random(6)*10);
      roll = random(6) + random(6) + dm;
      if (roll < 2) roll = 2;
      if (roll > 12) roll = 12;
      roll -= 2;
      entry = goods[catagory][roll][0];
      bottom = goods[catagory][roll][1];
      top = goods[catagory][roll][2];
      while(1) {
	specific = (random(6)*10) + random(6);
	if ((specific >= bottom) && (specific <= top)) break;
       }
      specific = (((specific/10)-1)*6) + (specific%10);
      cost = 4000 + code_cost_mod + (src_TL*100);
/* Begin NON-STANDARD MT cost modifiers */
      cost *= (cost_mult[entry] + random(6) + random(6));
      cost /= 100;
/* End NON-STANDARD MT cost modifiers */
      fprintf(fd, "%s - Cr. %5d/ton\n", product[entry][specific], cost);
     }
   }
  if (minor_cargo > 0) {
    fprintf(fd, "Minor Cargo:\n");
    for (i=0; i<minor_cargo; i++) {
      fprintf(fd, "  Lot #%2d: %2d tons - ", i+1, random(6)*5);
      roll = random(6) + random(6) + dm;
      if (roll < 2) roll = 2;
      if (roll > 12) roll = 12;
      roll -= 2;
      entry = goods[catagory][roll][0];
      bottom = goods[catagory][roll][1];
      top = goods[catagory][roll][2];
      while(1) {
	specific = (random(6)*10) + random(6);
	if ((specific >= bottom) && (specific <= top)) break;
       }
      specific = (((specific/10)-1)*6) + (specific%10);
      cost = 4000 + code_cost_mod + (src_TL*100);
/* Begin NON-STANDARD MT cost modifiers */
      cost *= (cost_mult[entry] + random(6) + random(6));
      cost /= 100;
/* End NON-STANDARD MT cost modifiers */
      fprintf(fd, "%s - Cr. %5d/ton\n", product[entry][specific], cost);
     }
   }
  if (inc_cargo > 0) {
    fprintf(fd, "Incidental Cargo:\n");
    for (i=0; i<inc_cargo; i++) {
      fprintf(fd, "  Lot #%2d: %2d tons - ", i+1, random(6));
      roll = random(6) + random(6) + dm;
      if (roll < 2) roll = 2;
      if (roll > 12) roll = 12;
      roll -= 2;
      entry = goods[catagory][roll][0];
      bottom = goods[catagory][roll][1];
      top = goods[catagory][roll][2];
      while(1) {
	specific = (random(6)*10) + random(6);
	if ((specific >= bottom) && (specific <= top)) break;
       }
      specific = (((specific/10)-1)*6) + (specific%10);
      cost = 4000 + code_cost_mod + (src_TL*100);
/* Begin NON-STANDARD MT cost modifiers */
      cost *= (cost_mult[entry] + random(6) + random(6));
      cost /= 100;
/* End NON-STANDARD MT cost modifiers */
      fprintf(fd, "%s - Cr. %5d/ton\n", product[entry][specific], cost);
     }
   }
  fclose(fd);
}


int yes_or_no(c)
char c;
{
  if (c == 'Y') return(TRUE);
  if (c == 'y') return(TRUE);
  if (c == 'N') return(FALSE);
  if (c == 'n') return(FALSE);
  return(BAD_VAL);
}


int cvt_hex(c)
char c;
{
  switch(c) {
    case '0' :
    case '1' :
    case '2' :
    case '3' :
    case '4' :
    case '5' :
    case '6' :
    case '7' :
    case '8' :
    case '9' : return ((int) (c - '0'));
	       break;
    case 'A' :
    case 'a' : return(10);
	       break;
    case 'B' :
    case 'b' : return(11);
	       break;
    case 'C' :
    case 'c' : return(12);
	       break;
    case 'D' :
    case 'd' : return(13);
	       break;
    case 'E' :
    case 'e' : return(14);
	       break;
    case 'F' :
    case 'f' : return(15);
	       break;
    case 'G' :
    case 'g' : return(16);
	       break;
    case 'H' :
    case 'h' : return(17);
	       break;
    case 'I' :
    case 'i' : return(18);
	       break;
    default  : return(-1);
	       break;
   } /* switch */
}


get_trade_codes()
{
  char *status, line[81], code[3];
  int len, i, j, flag, valid;

  code_cost_mod = 0;
  for (j=0; j<6; j++)
    trade_table[j] = 0;
  flag = TRUE;
  while (flag) {
    printf("Enter trade codes for src. world: ");
    status = fgets(line, 81, stdin);
    len = strlen(line);
    for (i=0; i<len; i++) {
      if ((line[i] == ',') || (line[i] == ' ')) continue;
      if (i+1 < len) {
	code[0] = line[i];
	code[1] = line[++i];
	code[2] = NULL;
       } /* if */
      else
	continue;
      valid = FALSE;
      if (!strcmp(code, "Ag"))
	{trade_table[0]++; valid++; code_cost_mod -= 1000;}

      if (!strcmp(code, "Wa"))
	{trade_table[1]++; valid++;}
      if (!strcmp(code, "Ri"))
	{trade_table[1]++; valid++; code_cost_mod += 1000;}

      if (!strcmp(code, "As"))
	{trade_table[2]++; valid++; code_cost_mod -= 1000;}
      if (!strcmp(code, "Va"))
	{trade_table[2]++; valid++; code_cost_mod += 1000;}
      if (!strcmp(code, "De"))
	{trade_table[2]++; valid++; code_cost_mod += 1000;}
      if (!strcmp(code, "Na"))
	{trade_table[2]++; valid++; code_cost_mod += 1000;}

      if (!strcmp(code, "Ni"))
	{trade_table[3]++; valid++; code_cost_mod += 1000;}

      if (!strcmp(code, "In"))
	{trade_table[4]++; valid++; code_cost_mod -= 1000;}

      if (!strcmp(code, "Ba"))
	{trade_table[5]++; valid++; barren++; code_cost_mod += 1000;}
      if (!strcmp(code, "Fl"))
	{trade_table[5]++; valid++; code_cost_mod += 1000;}
      if (!strcmp(code, "Hi"))
	{trade_table[5]++; valid++; code_cost_mod -= 1000;}
      if (!strcmp(code, "Ic"))
	{trade_table[5]++; valid++;}
      if (!strcmp(code, "Lo"))
	{trade_table[5]++; valid++; code_cost_mod += 1000;}
      if (!strcmp(code, "Po"))
	{trade_table[5]++; valid++; code_cost_mod -= 1000;}

      if (!valid) {
	printf("Invalid trade code '%s'\n", code);
	printf("Valid trade codes are: Ag, Ni, Wa, Ri, In, As, Va,\n");
	printf("                       De, Na, Ba, Fl, Hi, Ic, Lo, Po\n");
	for (j=0; j<6; j++)
	  trade_table[j] = 0;
	i += len;
       } /* if */
     } /* for */
    if (valid) return(TRUE);
   } /* while */
}


#ifdef BSD
#define MAX_RAND	2147483647
#else
#define MAX_RAND	32767
#endif

/* random(n) - a random integer generator with 20 bit resolution */

int random_first = 1;

random(n)	/* generate a number from 1 to n, n < 1.0EE6 */
int n;
{
	float fval;
	int val;

	if (random_first) {
		srand((unsigned int) time((long *)0));
		random_first=0;
	}
	fval = ((float) rand()) / MAX_RAND;
	val = fval * ((float) n);
	return(++val);
}
