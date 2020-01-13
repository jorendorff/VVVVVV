#include "vxml.h"

#include <memory>
#include <sstream>
#include <cassert>

#include "tinyxml.h"
#include "FileSystemUtils.h"

VVVVVV_XML_Element * vvvvvv_xml_root(VVVVVV_XML_Document *doc) {
    return doc->FirstChildElement();
}

const char * vvvvvv_xml_name(VVVVVV_XML_Element *element) {
    return element->Value();
}

const char * vvvvvv_xml_text(VVVVVV_XML_Element *element) {
    return element->GetText();
}

void vvvvvv_xml_query_int_attribute(VVVVVV_XML_Element *element, const char *attr_name, int *result) {
    element->QueryIntAttribute(attr_name, result);
}


VVVVVV_XML_Element * vvvvvv_xml_first_child_element(VVVVVV_XML_Element *parent) {
    return parent->FirstChildElement();
}

VVVVVV_XML_Element * vvvvvv_xml_first_child_element_named(VVVVVV_XML_Element *parent, const char *name) {
    return parent->FirstChildElement(name);
}

VVVVVV_XML_Element * vvvvvv_xml_next_sibling_element(VVVVVV_XML_Element *child) {
    return child->NextSiblingElement();
}


VVVVVV_XML_Element* vvvvvv_xml_new_element(const char *tag) {
    return new TiXmlElement(tag);
}

void vvvvvv_xml_set_attribute(VVVVVV_XML_Element *element, const char *attr_name, int value) {
    element->SetAttribute(attr_name, value);
}

void vvvvvv_xml_append(VVVVVV_XML_Element *parent, VVVVVV_XML_Element *child) {
    parent->LinkEndChild(child);
}

void vvvvvv_xml_append_bool(VVVVVV_XML_Element *parent, const char *tag_name, bool value) {
    vvvvvv_xml_append_str(parent, tag_name, value ? "1" : "0");
}

void vvvvvv_xml_append_int(VVVVVV_XML_Element *parent, const char *tag_name, int value) {
    std::ostringstream os;
    os << value;
    std::string str_value = os.str();
    vvvvvv_xml_append_str(parent, tag_name, str_value.c_str());
}

void vvvvvv_xml_append_str(VVVVVV_XML_Element *parent, const char *tag_name, const char *value) {
    VVVVVV_XML_Element *child = new TiXmlElement(tag_name);
    child->LinkEndChild(new TiXmlText(value));
    parent->LinkEndChild(child);
}

void vvvvvv_xml_set_text(VVVVVV_XML_Element *parent, const char *text) {
    assert(parent->FirstChild() == NULL);
    parent->LinkEndChild(new TiXmlText(text));
}

void vvvvvv_xml_append_comment(VVVVVV_XML_Element *parent, const char *comment_text) {
    TiXmlComment *comment = new TiXmlComment();
    comment->SetValue(comment_text);
    parent->LinkEndChild(comment);
}

bool vvvvvv_xml_save(const char *filename, VVVVVV_XML_Element* root_element) {
    TiXmlDocument doc;
    TiXmlDeclaration *decl = new TiXmlDeclaration( "1.0", "", "" );
    doc.LinkEndChild( decl );
    doc.LinkEndChild( root_element );
    return FILESYSTEM_saveTiXmlDocument(filename, &doc);
}

VVVVVV_XML_Document* vvvvvv_xml_load(const char *filename) {
    unsigned char *mem = NULL;
    FILESYSTEM_loadFileToMemory(filename, &mem, NULL);
    if (mem == NULL) {
        return NULL;
    }

    std::unique_ptr<TiXmlDocument> doc(new TiXmlDocument);
    doc->Parse((const char*) mem);
    FILESYSTEM_freeMemory(&mem);
    return doc.release();
}

void vvvvvv_xml_free(VVVVVV_XML_Document *document) {
    std::unique_ptr<TiXmlDocument> doc;
    doc.reset(document);
}
