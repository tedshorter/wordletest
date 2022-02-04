#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int lettercount2(char *a, char *b)
{
  unsigned char hits[26];
  int count;
  
  for (int i=0; i<sizeof(hits); i++) {
    hits[i]=0;
  }

  for (int i=0; a[i]!=0; i++) {
    hits[tolower(a[i])-'a'] = 1;
  }
  for (int i=0; b[i]!=0; i++) {
    hits[tolower(b[i])-'a'] = 1;
  }
  
  count = 0;
  for (int i=0; i<sizeof(hits); i++) {
    if (hits[i]) count++;
  }

  /* printf ("%s %s: %d\n", a, b, count); */
  
  return count;  
}

int lettercount3 (char *a, char *b, char *c)
{
  unsigned char hits[26];
  int count;
  
  for (int i=0; i<sizeof(hits); i++) {
    hits[i]=0;
  }

  for (int i=0; a[i]!=0; i++) {
    hits[tolower(a[i])-'a'] = 1;
  }
  for (int i=0; b[i]!=0; i++) {
    hits[tolower(b[i])-'a'] = 1;
  }
  for (int i=0; c[i]!=0; i++) {
    hits[tolower(c[i])-'a'] = 1;
  }
  
  count = 0;
  for (int i=0; i<sizeof(hits); i++) {
    if (hits[i]) count++;
  }

  /* printf ("%s %s %s: %d\n", a, b, c, count); */
  
  return count;  
}

int lettercount4 (char *a, char *b, char *c, char *d)
{
  unsigned char hits[26];
  int count;
  
  for (int i=0; i<sizeof(hits); i++) {
    hits[i]=0;
  }

  for (int i=0; a[i]!=0; i++) {
    hits[tolower(a[i])-'a'] = 1;
  }
  for (int i=0; b[i]!=0; i++) {
    hits[tolower(b[i])-'a'] = 1;
  }
  for (int i=0; c[i]!=0; i++) {
    hits[tolower(c[i])-'a'] = 1;
  }
  for (int i=0; d[i]!=0; i++) {
    hits[tolower(d[i])-'a'] = 1;
  }
  
  count = 0;
  for (int i=0; i<sizeof(hits); i++) {
    if (hits[i]) count++;
  }

  /* printf ("%s %s %s %s: %d\n", a, b, c, d, count); */
  
  return count;  
}

int lettercount5 (char *a, char *b, char *c, char *d, char *e)
{
  unsigned char hits[26];
  int count;
  
  for (int i=0; i<sizeof(hits); i++) {
    hits[i]=0;
  }

  for (int i=0; a[i]!=0; i++) {
    hits[tolower(a[i])-'a'] = 1;
  }
  for (int i=0; b[i]!=0; i++) {
    hits[tolower(b[i])-'a'] = 1;
  }
  for (int i=0; c[i]!=0; i++) {
    hits[tolower(c[i])-'a'] = 1;
  }
  for (int i=0; d[i]!=0; i++) {
    hits[tolower(d[i])-'a'] = 1;
  }
  for (int i=0; e[i]!=0; i++) {
    hits[tolower(e[i])-'a'] = 1;
  }
  
  count = 0;
  for (int i=0; i<sizeof(hits); i++) {
    if (hits[i]) count++;
  }

  /* printf ("%s %s %s %s %s: %d\n", a, b, c, d, e, count); */
  
  return count;  
}


int main()
{
  char words[200000][6];
  char t_word[10];
  int wcount;
  FILE *fp;
  int w1, w2, w3, w4, w5;
  int b1, b2, b3, b4, b5;
  int num_letters;
  int most_letters;

  int force = 3610;
  
  if ((fp=fopen("wordlist.txt", "r"))==NULL) {
    printf ("Could not open wordlist\n");
    exit (1);
  }

  for (wcount=0; (fgets(t_word, 10, fp))!=0; wcount++) {
    t_word[5]=0;
    strcpy(words[wcount], t_word);
  }
  fclose (fp);
  
  printf ("loaded %d words (%s).\n", wcount, words[force]);

#if 1
  /****  5-word combos ****/
  most_letters=0;
  for (w1=0; w1<wcount-4; w1++) {
    for (w2=w1+1; w2<wcount-3; w2++) {
      if (lettercount2(words[w1],words[w2])==10) {
	for (w3=w2+1; w3<wcount-2; w3++) {
	  if (lettercount3(words[w1],words[w2],words[w3])==15) {
	    for (w4=w3+1; w4<wcount-1; w4++) {
	      if (lettercount4(words[w1],words[w2],words[w3],words[w4])==20) {
		for (w5=w4+1; w5<wcount; w5++) {	      
		  num_letters = lettercount5(words[w1],words[w2],words[w3],words[w4],words[w5]);
		  if (num_letters >= most_letters) {
		    most_letters = num_letters;
		    b1=w1; b2=w2; b3=w3; b4=w4; b5=w5;
		    /* printf ("Best so far: %s %s %s %s %s - %d\n", words[w1], words[w2], words[w3], words[w4], words[w5], num_letters);*/

		    if (num_letters==24) {
		      printf ("%s %s %s %s %s\n", words[w1], words[w2], words[w3], words[w4], words[w5]);
		    }
		  }
		}
	      }
	    }
	  }
	}
      }
    }
    if ((w1 % 10)==9) {
      fprintf (stderr, "%5.2f%% Done.\n", (((float)100*w1)/wcount));
    }
  }
#else

  /**** 4 word combos ****/ 
  most_letters=0;
  /*w1 = force; {*/
  for (w1=0; w1<wcount-3; w1++) {
    for (w2=w1+1; w2<wcount-2; w2++) {
      if (lettercount2(words[w1],words[w2])==10) {
	for (w3=w2+1; w3<wcount-1; w3++) {
	  if (lettercount3(words[w1],words[w2],words[w3])==15) {
	    for (w4=w3+1; w4<wcount; w4++) {
	      num_letters = lettercount4(words[w1],words[w2],words[w3],words[w4]);
	      if (num_letters >= most_letters) {
		/*printf ("Best so far: %s %s %s %s - %d\n", words[w1], words[w2], words[w3], words[w4], num_letters);*/
		most_letters = num_letters;
		b1=w1; b2=w2; b3=w3; b4=w4;
		if (num_letters==20) {
		  printf ("%s %s %s %s\n", words[w1], words[w2], words[w3], words[w4]);
		}
	      }
	    }
	  }
	}
      }
    }
    if ((w1 % 10)==9) {
      fprintf (stderr, "%5.2f%% Done.\n", (((float)100*w1)/wcount));
    }
  }
#endif

  
}
