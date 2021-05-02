/* GIMP RGB C-Source image dump (boulder.c) */

static const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel; /* 2:RGB16, 3:RGB, 4:RGBA */ 
  unsigned char	 pixel_data[64 * 36 * 2 + 1];
} boulder_img = {
  64, 36, 2,
  "\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370"
  "\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370"
  "\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370"
  "\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370"
  "\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370"
  "\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370"
  "\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370(B(B(B(B(B(B"
  "(B(B(B(B(B(Be)e)e)\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370"
  "\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370"
  "\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370"
  "\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370(B(B(B(B(B(B"
  "(B\226\265\226\265(B(B\226\265\226\265\226\265\226\265\226\265(B\226\265"
  "\226\265\226\265e)e)e)\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000"
  "\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000"
  "\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000"
  "\370\000\370\000\370\000\370\000\370\000\370\000\370(B(B(B\226\265\226\265\226\265\226"
  "\265\226\265\226\265\226\265\226\265\226\265(B(B\226\265\226\265(B(B(B(B"
  "\226\265\226\265\226\265e)e)e)e)e)\000\370\000\370\000\370\000\370\000\370\000\370\000"
  "\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000"
  "\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000"
  "\370\000\370\000\370\000\370(B(B(B\226\265\226\265(B(B(B(B\226\265\226\265\226"
  "\265\226\265\226\265\226\265\226\265\226\265\226\265\226\265(B(B(B(B(B\226"
  "\265\226\265e)(B(Be)e)e)e)e)\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000"
  "\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000"
  "\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370(B(B\226\265\226"
  "\265\226\265(B(B\226\265(B(B\226\265\226\265\226\265\226\265\226\265\226"
  "\265\226\265\226\265\226\265\226\265(B(B\226\265(B\226\265(B\226\265\226"
  "\265e)(B(Be)(B(Be)e)e)e)\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370"
  "\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370"
  "\000\370\000\370\000\370\000\370\000\370(B(B\226\265(B(B(B(B\226\265(B(B\226\265(B"
  "\226\265\226\265\226\265\226\265\226\265\226\265\226\265\226\265\226\265"
  "(B(B\226\265\226\265(B(B(B\226\265\226\265e)e)e)e)(Be)(B(Be)e)e)\000\370\000"
  "\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000"
  "\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370(B\226\265\226\265\226"
  "\265\226\265\226\265\226\265\226\265(B\226\265\226\265\226\265\226\265\226"
  "\265\226\265(B\226\265\226\265\226\265\226\265\226\265\226\265\226\265\226"
  "\265(B(B(B\226\265(B\226\265e)e)\226\265e)e)e)e)(Be)e)e)e)e)e)\000\370\000\370"
  "\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370"
  "\000\370\000\370\000\370\000\370\000\370(B(B(B\226\265(B\226\265(B(B\226\265\226\265"
  "\226\265\226\265\226\265\226\265\226\265\226\265(B\226\265\226\265\226\265"
  "\226\265\226\265\226\265\226\265\226\265\226\265(B(B(B(B\226\265\226\265"
  "(B(B(B\226\265e)e)e)e)e)e)e)(B(Be)\000\370\000\370\000\370\000\370\000\370\000\370\000"
  "\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370(B(B\226"
  "\265\226\265\226\265\226\265(B(B\226\265\226\265\226\265\226\265\226\265"
  "\226\265\226\265\226\265\226\265\226\265\226\265\226\265\226\265\226\265"
  "\226\265\226\265\226\265(B\226\265\226\265(B(B\226\265\226\265(B\226\265"
  "\226\265(B(Be)e)e)e)e)e)\226\265e)(B(Be)e)\000\370\000\370\000\370\000\370\000\370"
  "\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370(B\226\265(B"
  "\226\265\226\265\226\265(B\226\265\226\265\226\265\226\265\226\265\226\265"
  "\226\265(B\226\265\226\265\226\265\226\265\226\265\226\265\226\265(B\226"
  "\265\226\265\226\265(B\226\265(B(B(B(B\226\265(B\226\265\226\265\226\265"
  "(B(B(Be)e)e)e)e)e)e)(B(Be)e)\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000"
  "\370\000\370\000\370\000\370\000\370(B(B(B(B(B(B(B(B(B\226\265\226\265\226\265\226"
  "\265\226\265\226\265\226\265\226\265\226\265\226\265\226\265\226\265\226"
  "\265\226\265\226\265\226\265\226\265\226\265\226\265\226\265(B\226\265(B"
  "(B\226\265(B(B\226\265\226\265(B(B(B(Be)(Be)e)e)e)e)(B(Be)e)\000\370\000\370"
  "\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370(B\226\265(B(B\226"
  "\265(B(B\226\265\226\265\226\265\226\265\226\265\226\265\226\265\226\265"
  "\226\265(B(B\226\265\226\265\226\265\226\265\226\265\226\265\226\265\226"
  "\265\226\265\226\265\226\265(B\226\265(B(B(B\226\265(B\226\265(B(B(B(B\226"
  "\265\226\265(B(Be)e)(Be)e)e)(B(Be)\000\370\000\370\000\370\000\370\000\370\000\370\000"
  "\370\000\370\000\370(B(B\226\265\226\265\226\265(B\226\265\226\265(B\226\265"
  "\226\265\226\265\226\265\226\265\226\265\226\265\226\265(B\226\265\226\265"
  "(B\226\265\226\265\226\265\226\265\226\265\226\265\226\265\226\265\226\265"
  "(B\226\265(B(B(B\226\265\226\265\226\265(B\226\265(B(B(B\226\265(B(Be)e)"
  "(B(Be)e)(B(B(Be)\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370(B\226\265"
  "\226\265(B\226\265(B(B(B(B\226\265\226\265\226\265(B\226\265\226\265\226"
  "\265\226\265\226\265\226\265(B\226\265\226\265(B(B\226\265\226\265\226\265"
  "\226\265(B(B(B\226\265\226\265(B(B(B(B(B(B(B\226\265(B(B(B(B\226\265\226"
  "\265e)e)e)e)e)e)e)e)(Be)\000\370\000\370\000\370\000\370\000\370\000\370\000\370(B\226"
  "\265(B\226\265\226\265\226\265\226\265\226\265(B\226\265\226\265\226\265"
  "\226\265\226\265\226\265\226\265(B\226\265\226\265(B\226\265\226\265(B\226"
  "\265\226\265\226\265\226\265\226\265(B(B(B(B\226\265(B(B(B(B\226\265(B(B"
  "(B(B\226\265\226\265(Be)e)e)e)e)e)(B(Be)e)e)(Be)\000\370\000\370\000\370\000\370"
  "\000\370\000\370(B\226\265(B(B\226\265(B\226\265\226\265(B\226\265\226\265\226"
  "\265\226\265\226\265\226\265\226\265\226\265\226\265\226\265(B\226\265\226"
  "\265(B\226\265\226\265\226\265\226\265\226\265\226\265(B\226\265\226\265"
  "\226\265(B(B(B(B(B\226\265(B(B(B(B(B(Be)e)e)(B\226\265e)e)(Be)(Be)(Be)\000"
  "\370\000\370\000\370\000\370\000\370\000\370(B\226\265\226\265\226\265(B\226\265(B"
  "(B(B\226\265\226\265(B\226\265\226\265\226\265\226\265\226\265\226\265\226"
  "\265\226\265\226\265\226\265\226\265\226\265\226\265\226\265\226\265\226"
  "\265(B\226\265\226\265(B\226\265(B\226\265(B(B(B(B(B\226\265\226\265(B(B"
  "\226\265(Be)(B(B\226\265\226\265e)e)e)e)e)(Be)e)\000\370\000\370\000\370\000\370"
  "\000\370(B(B\226\265(B(B\226\265\226\265(B\226\265\226\265\226\265(B\226\265"
  "\226\265\226\265\226\265\226\265\226\265\226\265\226\265\226\265\226\265"
  "\226\265\226\265\226\265\226\265\226\265\226\265(B(B(B(B\226\265(B\226\265"
  "(B(B\226\265\226\265\226\265\226\265\226\265(B(B(Be)e)\226\265e)\226\265"
  "e)(Be)e)e)e)e)(Be)\000\370\000\370\000\370\000\370\000\370(B(B\226\265(B(B\226\265"
  "(B\226\265\226\265\226\265\226\265\226\265\226\265\226\265\226\265(B\226"
  "\265\226\265\226\265\226\265\226\265\226\265\226\265\226\265\226\265\226"
  "\265\226\265\226\265\226\265(B(B\226\265\226\265(B\226\265(B\226\265(B(B"
  "\226\265\226\265(B(B(B(Be)e)e)\226\265e)\226\265e)e)(Be)e)(B(Be)\000\370\000"
  "\370\000\370\000\370\000\370(B\226\265\226\265\226\265(B(B(B\226\265\226\265\226"
  "\265\226\265\226\265\226\265\226\265\226\265\226\265\226\265\226\265\226"
  "\265\226\265\226\265\226\265\226\265\226\265\226\265\226\265\226\265\226"
  "\265\226\265\226\265(B(B(B(B\226\265(B\226\265(B(B(B(B(B(B\226\265e)e)(B"
  "e)\226\265\226\265\226\265e)(Be)e)e)(Be)e)\000\370\000\370\000\370\000\370\000\370"
  "(B\226\265(B(B\226\265(B(B\226\265(B\226\265\226\265\226\265\226\265\226"
  "\265\226\265\226\265\226\265\226\265\226\265\226\265\226\265(B\226\265\226"
  "\265(B\226\265\226\265\226\265\226\265\226\265(B(B(B\226\265\226\265(B(B"
  "(B(B\226\265\226\265(Be)(Be)(Be)e)e)\226\265e)e)(B(Be)(B(Be)\000\370\000\370"
  "\000\370\000\370\000\370\000\370(B(B\226\265\226\265(B(B(B\226\265(B\226\265\226"
  "\265\226\265\226\265\226\265\226\265\226\265\226\265\226\265\226\265\226"
  "\265\226\265\226\265\226\265\226\265\226\265\226\265\226\265\226\265\226"
  "\265\226\265(B\226\265\226\265(B\226\265(B(B\226\265(Be)e)\226\265e)e)(B"
  "e)e)e)e)\226\265e)e)e)e)(B(B(Be)\000\370\000\370\000\370\000\370\000\370\000\370\000\370"
  "(B(B\226\265(B\226\265(B\226\265\226\265\226\265(B\226\265\226\265\226\265"
  "\226\265\226\265\226\265(B\226\265\226\265\226\265\226\265\226\265\226\265"
  "\226\265\226\265\226\265\226\265(B\226\265\226\265\226\265(B(B(B(B(B(B(B"
  "e)(B(B(B\226\265e)e)\226\265e)e)\226\265e)e)(Be)(B(Be)\000\370\000\370\000\370"
  "\000\370\000\370\000\370\000\370\000\370\000\370(B\226\265\226\265(B(B(B(B\226\265\226"
  "\265\226\265\226\265\226\265\226\265\226\265\226\265(B\226\265\226\265(B"
  "\226\265\226\265\226\265\226\265\226\265\226\265\226\265(B(B\226\265\226"
  "\265(B(B(B(B(B(Be)e)(Be)e)e)e)e)e)e)e)e)e)e)e)e)(Be)e)\000\370\000\370\000\370"
  "\000\370\000\370\000\370\000\370\000\370\000\370\000\370(B\226\265\226\265\226\265(B(B"
  "(B(B\226\265(B\226\265\226\265\226\265\226\265\226\265\226\265\226\265\226"
  "\265\226\265\226\265(B(B\226\265\226\265(B(B(B(B(B(B(B(B\226\265(Be)e)e)"
  "e)e)e)e)\226\265e)(Be)e)(Be)e)(B(B(Be)\000\370\000\370\000\370\000\370\000\370\000\370"
  "\000\370\000\370\000\370\000\370\000\370(B(B\226\265\226\265\226\265(B(B(B(B(B\226"
  "\265(B\226\265\226\265\226\265\226\265\226\265\226\265\226\265\226\265\226"
  "\265\226\265\226\265(B(B\226\265(B(B(B(B(B\226\265(B(Be)e)e)\226\265\226"
  "\265\226\265e)e)e)e)e)e)e)(B(B(B(Be)\000\370\000\370\000\370\000\370\000\370\000\370"
  "\000\370\000\370\000\370\000\370\000\370\000\370\000\370(B(B(B\226\265\226\265(B(B\226"
  "\265\226\265\226\265(B\226\265\226\265\226\265\226\265\226\265\226\265\226"
  "\265\226\265\226\265\226\265\226\265(B(B(B(B\226\265(B\226\265\226\265\226"
  "\265e)(Be)\226\265e)\226\265e)e)e)(B(Be)e)e)(B(B(B(Be)\000\370\000\370\000\370"
  "\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370"
  "\000\370(B(B\226\265\226\265(B\226\265(B\226\265\226\265\226\265\226\265\226"
  "\265\226\265\226\265(B\226\265\226\265\226\265\226\265(B(B(B(B(B\226\265"
  "(B(B(B\226\265e)\226\265e)\226\265e)e)\226\265e)e)e)e)(Be)e)(B(Be)e)\000\370"
  "\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370"
  "\000\370\000\370\000\370\000\370\000\370\000\370(B(B\226\265\226\265\226\265\226\265"
  "\226\265(B(B\226\265\226\265\226\265\226\265\226\265\226\265(B(B(B(B\226"
  "\265\226\265\226\265(B\226\265\226\265\226\265e)e)\226\265e)e)e)e)e)e)(B"
  "e)e)e)e)(Be)e)\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370"
  "\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370"
  "(B(B(B\226\265\226\265(B(B(B\226\265\226\265(B\226\265\226\265(B\226\265"
  "\226\265\226\265\226\265\226\265\226\265\226\265\226\265(B(Be)e)e)\226\265"
  "\226\265e)e)e)(B(B(B(B(B(Be)e)\000\370\000\370\000\370\000\370\000\370\000\370\000\370"
  "\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370"
  "\000\370\000\370\000\370\000\370\000\370\000\370\000\370(B(B\226\265\226\265(B\226\265"
  "\226\265(B(B(B(B(B(B(B(B(B\226\265\226\265(B(B(Be)e)e)e)(B(B(B(B(B(B(Be)"
  "e)e)e)\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370"
  "\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370"
  "\000\370\000\370\000\370\000\370\000\370\000\370\000\370(B(B(B(B(B\226\265\226\265(B(B"
  "\226\265(B\226\265(B(Be)e)e)e)e)e)e)e)(B(B(B(Be)e)e)e)e)\000\370\000\370\000\370"
  "\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370"
  "\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370"
  "\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370(B(B(B(B(B(B"
  "(B(B(B\226\265\226\265\226\265\226\265e)e)\226\265\226\265\226\265e)e)e)"
  "e)e)\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000"
  "\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000"
  "\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000"
  "\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000"
  "\370\000\370(B(B(B(B(B(Be)e)e)e)\000\370\000\370\000\370\000\370\000\370\000\370\000\370"
  "\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370"
  "\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370"
  "\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370"
  "\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370"
  "\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370"
  "\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370"
  "\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370\000\370"
  "\000\370",
};
