
#define ame_Level_7

#define LogApp
//#define MonkeyFileLogApp

#include "DefaultLogging.hpp"
#include "Logger.hpp"

#include "MonkeyFile.hpp"
#include "DefaultMonkeyFile.hpp"
#include "TextExporter.hpp"
#include "TextImporter.hpp"

using namespace ame;

DefaultMonkeyFile<SDFileSystemClass> file = SD;

void setup() {
  Serial.begin(9600);
  initializeLogger(new DefaultLogging(&Serial, true, false));
  LogClass("MonkeyFile");

  file.setRootPathFile("monkey");
  
  file.deleteFile("memory.txt");
  file.createFile("memory.txt");
  
  TextExporter exporter;
  exporter.write("parent", "name");
  file.writeText(exporter.getText(), "memory.txt");
}

void loop() {
  TextImporter importer = file.readText("memory.txt");
  Note number = importer.read("parent", "");
  Serial.println(number);
}
