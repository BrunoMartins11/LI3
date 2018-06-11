#!/bin/bash

rm -rf *.txt target/

mvn clean package

mycommand="java -jar target/program-1.0-SNAPSHOT-jar-with-dependencies.jar "$@

echo $mycommand
$mycommand
