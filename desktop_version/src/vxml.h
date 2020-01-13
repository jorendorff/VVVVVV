#ifndef VXML_H_
#define VXML_H_

class TiXmlDocument;
typedef TiXmlDocument VVVVVV_XML_Document;
class TiXmlElement;
typedef TiXmlElement VVVVVV_XML_Element;


extern "C" {
    VVVVVV_XML_Element * vvvvvv_xml_root(VVVVVV_XML_Document *doc);

    const char * vvvvvv_xml_name(VVVVVV_XML_Element *element);

    const char * vvvvvv_xml_text(VVVVVV_XML_Element *element);

    void vvvvvv_xml_query_int_attribute(VVVVVV_XML_Element *element, const char *attr_name, int *result);

    VVVVVV_XML_Element * vvvvvv_xml_first_child_element(VVVVVV_XML_Element *parent);

    VVVVVV_XML_Element * vvvvvv_xml_first_child_element_named(VVVVVV_XML_Element *parent, const char *name);

    VVVVVV_XML_Element * vvvvvv_xml_next_sibling_element(VVVVVV_XML_Element *child);

    VVVVVV_XML_Element * vvvvvv_xml_new_element(const char *tag);

    void vvvvvv_xml_set_attribute(VVVVVV_XML_Element *element, const char *attr_name, int value);

    void vvvvvv_xml_append(VVVVVV_XML_Element *parent, VVVVVV_XML_Element *child);

    void vvvvvv_xml_append_bool(VVVVVV_XML_Element *parent, const char *tag_name, bool value);

    void vvvvvv_xml_append_int(VVVVVV_XML_Element *parent, const char *tag_name, int value);

    void vvvvvv_xml_append_str(VVVVVV_XML_Element *parent, const char *tag_name, const char *value);

    // Call this only if the element is empty.
    void vvvvvv_xml_set_text(VVVVVV_XML_Element *parent, const char *text);

    void vvvvvv_xml_append_comment(VVVVVV_XML_Element *parent, const char *comment_text);

    bool vvvvvv_xml_save(const char *filename, VVVVVV_XML_Element *root_element);

    VVVVVV_XML_Document * vvvvvv_xml_load(const char *filename);

    void vvvvvv_xml_free(VVVVVV_XML_Document *document);

}

#endif // VXML_H_

