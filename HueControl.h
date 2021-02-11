
/* File foo.  */
#ifndef FILE_FOO_SEEN
#define FILE_FOO_SEEN

  #include <string.h>
  
  
  
  void group(byte group_id, bool current_state);

  void light(byte light_id, bool current_state);

  void color(char device_type[], byte id, int red, int green, int blue);

  void brightness(char device_type[], byte id, int brightness);
  


// IP or Hostname of Hue gateway
extern String ip;

// Hue gateway user name
extern String user_name ;

#endif /* !FILE_FOO_SEEN */