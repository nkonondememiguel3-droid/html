#ifndef HTML_PARSER_H
#define HTML_PARSER_H

// #include "lexbor/html/html.h"
#include "lexbor/html/interface.h"

typedef struct {
  lxb_html_document_t *document;
  lxb_char_t *html_source;
  size_t html_source_size;
} __html__;

__html__ *html_init(unsigned char *html_source, size_t html_source_size);
lxb_status_t html_parse(__html__ *html);
void html_dump(__html__ *html);
void html_destroy(__html__ *html);

#endif // HTML_PARSER_H
