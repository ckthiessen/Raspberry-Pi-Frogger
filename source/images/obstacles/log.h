/* GIMP RGB C-Source image dump (log.c) */

static const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel; /* 2:RGB16, 3:RGB, 4:RGBA */ 
  unsigned char	 pixel_data[64 * 36 * 2 + 1];
} log_image = {
  64, 36, 2,
  "\344a\344a\344a\344a\344a\344a;\377;\377;\377;\377;\377;\377;\377;\377;\377"
  ";\377;\377;\377;\377;\377;\377;\377;\377\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a;\377;\377;\377;\377;"
  "\377;\377;\377;\377;\377;\377;\377;\377;\377;\377;\377;\377;\377\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a;\377;\377;\377;\377;\377;\377;"
  "\377;\377;\377;\377\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a;\377;"
  "\377;\377;\377;\377;\377;\377;\377;\377;\377\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a;\377;\377;\377;"
  "\377;\377;\377;\377;\377;\377;\377;\377;\377\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a;\377;\377;\377;\377;\377;\377;\377;\377;\377;\377;\377;\377\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a;\377;\377;\377;\377;\377\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a;\377;"
  "\377;\377;\377;\377;\377;\377;\377;\377;\377;\377;\377;\377\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a;\377;"
  "\377;\377;\377;\377\344a\344a\344a\344a\344a\344a\344a\344a;\377;\377;\377"
  ";\377;\377;\377;\377;\377;\377;\377;\377;\377;\377;\377;\377;\377;\377;\377"
  ";\377;\377\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a;\377;\377;\377;\377;\377;\377;\377;\377;\377;\377;\377;\377;\377;"
  "\377;\377;\377;\377;\377;\377;\377\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a;\377;\377;\377;\377;\377;\377;\377\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a;\377;\377;\377;"
  "\377;\377;\377;\377;\377;\377;\377;\377;\377;\377\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a;\377;\377;\377;\377\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a;\377;\377;\377;\377;\377;\377;\377;\377;\377;\377;\377;\377;\377\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a;\377;\377;\377;\377\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a;\377;\377;\377;\377;\377;"
  "\377\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a;"
  "\377;\377;\377;\377;\377;\377\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a;\377;\377;\377;\377;\377;\377;\377;\377;\377;\377\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a;\377;\377;\377;\377;\377;\377;\377;\377;\377;\377\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a;\377;"
  "\377;\377;\377;\377;\377;\377;\377\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a;\377;\377;\377;\377;\377;\377;\377;\377\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a;\377;\377;\377;\377;\377;\377;\377;\377;\377\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a;\377;"
  "\377;\377;\377;\377;\377;\377;\377;\377;\377;\377;\377;\377;\377;\377;\377"
  ";\377;\377;\377;\377\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a;\377;\377;\377;\377;\377;\377;\377;\377;\377;\377;\377;"
  "\377;\377;\377;\377;\377;\377;\377;\377;\377\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a;\377;\377;\377;\377;\377;\377;"
  "\377;\377;\377;\377;\377\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a;\377;\377;"
  "\377;\377;\377;\377;\377;\377;\377;\377;\377;\377;\377\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a;\377;\377;\377;\377;\377;\377;\377;\377;\377;\377;\377;\377;"
  "\377\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a;\377;\377;\377;\377;\377;\377;\377;\377;\377;\377;\377;\377\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a;\377;\377;\377;\377;\377;\377;\377;\377;\377;"
  "\377;\377;\377\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a;"
  "\377;\377;\377;\377;\377;\377\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a;\377;\377;\377;\377;\377;\377\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a;\377;\377;\377;\377;\377;\377;\377;\377;\377;\377;\377\344"
  "a\344a\344a\344a\344a\344a\344a;\377;\377;\377;\377;\377;\377;\377;\377;"
  "\377;\377;\377;\377\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a;\377;\377;\377;\377;\377;\377;"
  "\377;\377;\377;\377;\377\344a\344a\344a\344a\344a\344a\344a;\377;\377;\377"
  ";\377;\377;\377;\377;\377;\377;\377;\377;\377\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a;\377;\377;\377;\377;\377;\377;\377;\377;"
  "\377;\377;\377;\377;\377;\377;\377;\377\344a\344a\344a\344a\344a\344a;\377"
  ";\377;\377;\377;\377;\377;\377;\377;\377;\377;\377\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344"
  "a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a\344a;\377;\377;\377;"
  "\377;\377;\377;\377;\377;\377;\377;\377;\377;\377;\377;\377;\377\344a\344"
  "a\344a",
};
