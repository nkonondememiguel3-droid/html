#include "html_parser.h"

int main(int argc, char **argv) {

  unsigned char *html_source = "<div>Hello, world!</div>";
  __html__ *html = html_init(html_source, strlen((char *)html_source));
  html_parse(html);

  html_dump(html);

  html_destroy(html);

  return 0;
}
