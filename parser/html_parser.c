#include "html_parser.h"

/* #include "lexbor/html/html.h" */
#include <stdio.h>
#include <stdlib.h>

__html__ *html_init(unsigned char *html_source, size_t html_source_size) {

  if (html_source == NULL) {
    fprintf(stderr, "Should provide the html source.\n");
    return NULL;
  }

  /* if (strlen((const char *)html_source) != html_source_size) { */
  /*   html_source_size = strlen((const char *)html_source); */
  /* } */

  __html__ *html = (__html__ *)calloc(1, sizeof(__html__));
  if (html == NULL) {
    fprintf(stderr, "No enough memory available.\n");
    return NULL;
  }

  html->document = lxb_html_document_create();
  if (html->document == NULL) {
    fprintf(stderr, "Failed to create the html document.\n");
    return NULL;
  }

  html->html_source = html_source;
  html->html_source_size = html_source_size;

  return html;
}

lxb_status_t html_parse(__html__ *html) {

  lxb_status_t status = lxb_html_document_parse(
      html->document, html->html_source, html->html_source_size);

  if (status != LXB_STATUS_OK) {
    fprintf(stderr, "Failed to parse the %s html document.\n",
            html->html_source);
    lxb_html_document_destroy(html->document);
    return LXB_STATUS_ERROR;
  }
  printf("Parsed the html document.\n");

  return LXB_STATUS_OK;
}

static lxb_status_t callback(const lxb_char_t *data, size_t len, void *cxt) {
  (void)cxt;
  fwrite(data, 1, len, stdout);
  fflush(stdout);
  return LXB_STATUS_OK;
}

void html_dump(__html__ *html) {

  if (html == NULL || html->document == NULL)
    return;

  printf("Dumping the html: \n");
  lxb_html_serialize_tree_cb(lxb_dom_interface_node(html->document), callback,
                             NULL);
  printf("\n");
}

void html_destroy(__html__ *html) {
  lxb_html_document_destroy(html->document);

  free(html);
}
