package main.java.engine;

import javax.xml.parsers.*;

import main.java.common.Answer;
import main.java.common.Tag;
import org.xml.sax.*;
import org.xml.sax.helpers.*;

import java.time.LocalDate;
import java.util.*;
import java.io.*;

public class Parser {

        private static String convertToFileURL(String filename){
            String path = new File(filename).getAbsolutePath();
            if(File.separatorChar != '/'){
                path = path.replace(File.separatorChar, '/');
            }

            if(!path.startsWith("/")){
                path = "/" + path;
            }
            return "file:" + path;
        }

        /*public static void main(String[] args){
            Main_Struct s = Parser.multParse("/home/dunnadan/LI3/");
        }*/

        public static TCDCommunity parseAllFiles(String path){
            TCDCommunity tcd = new TCDCommunity();

            Parser.parse(path + "Posts.xml", tcd, 0);
            Parser.parse(path + "Users.xml", tcd, 1);
            Parser.parse(path + "Tags.xml", tcd, 2);

            return tcd;


        }

        private static void parse(String path, TCDCommunity tcd, int flag){

            SAXParserFactory parserFactor = SAXParserFactory.newInstance();
            parserFactor.setNamespaceAware(true);

            try{
                SAXParser parser = parserFactor.newSAXParser();

                XMLReader reader = parser.getXMLReader();
                if(flag == 0)
                    reader.setContentHandler(new PostParser(tcd));
                if(flag == 1)
                    reader.setContentHandler(new UserParser(tcd));
                if(flag == 2)
                    reader.setContentHandler(new TagsParser(tcd));

                reader.parse(convertToFileURL(path));

            }catch(IOException | SAXException | ParserConfigurationException e){
                System.out.println(e.getMessage());
            }

        }
    }

class PostParser extends DefaultHandler {

    private TCDCommunity tcd;

    public  PostParser(TCDCommunity tcd){
        this.tcd = tcd;
    }

    public void startElement(String namespaceURI, String localName, String qName, Attributes atts) throws SAXException {
        long id;                //Posts
        long ownerID;           //Posts
        long score;             //Posts
        long commentCount;      //Posts
        LocalDate date;         //Posts
        String title;           //Questions
        List<Tag> tags;         //Questions
        List<Answer> answers;   //Questions


    }

}