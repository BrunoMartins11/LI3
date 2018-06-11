package engine;

import common.Answer;
import common.Question;
import common.Tag;
import common.User;
import org.xml.sax.Attributes;
import org.xml.sax.SAXException;
import org.xml.sax.XMLReader;
import org.xml.sax.helpers.DefaultHandler;

import javax.xml.parsers.ParserConfigurationException;
import javax.xml.parsers.SAXParser;
import javax.xml.parsers.SAXParserFactory;
import java.io.File;
import java.io.IOException;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.util.List;



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

        public static void parseAllFiles(String path, TCDCommunity tcd){

            Parser.parse(path + "Users.xml", tcd, 0);
            Parser.parse(path + "Posts.xml", tcd, 1);
            Parser.parse(path + "Tags.xml", tcd, 2);


        }

        private static void parse(String path, TCDCommunity tcd, int flag){

            SAXParserFactory parserFactor = SAXParserFactory.newInstance();
            parserFactor.setNamespaceAware(true);

            try{
                SAXParser parser = parserFactor.newSAXParser();

                XMLReader reader = parser.getXMLReader();
                if(flag == 0)
                    reader.setContentHandler(new UserParser(tcd));
                if(flag == 1)
                    reader.setContentHandler(new PostParser(tcd));
                if(flag == 2)
                    reader.setContentHandler(new TagParser(tcd));

                reader.parse(convertToFileURL(path));

            }catch(IOException | SAXException | ParserConfigurationException e){
                System.out.println(e.getMessage());
            }

        }
    }

class PostParser extends DefaultHandler {

    private TCDCommunity tcd;


    public PostParser(TCDCommunity tcd) {
        this.tcd = tcd;
    }


    public void startElement(String namespaceURI, String localName, String qName, Attributes atts) {
        long id;                //Posts
        long ownerID;           //Posts
        long score;             //Posts
        long commentCount;      //Posts
        LocalDate date;         //Posts
        String title;           //Questions
        String tags;            //Questions
        long parentID;          //Answers

        if (atts.getLength() == 0) return;

        id = Long.parseLong(atts.getValue("Id"));
        ownerID = Long.parseLong(atts.getValue("OwnerUserId"));
        score = Long.parseLong(atts.getValue("Score"));
        commentCount = Long.parseLong(atts.getValue("CommentCount"));
        date = LocalDateTime.parse(atts.getValue("CreationDate")).toLocalDate();

        if (atts.getValue("PostTypeId").equals("1")) {
            title = atts.getValue("Title");
            tags = atts.getValue("Tags");

            Question q = new Question(id, ownerID, score, commentCount, date, title, tags);
            this.tcd.addPost(q);
        } else {
            if (atts.getValue("PostTypeId").equals("2")) {

                parentID = Long.parseLong(atts.getValue("ParentId"));
                Answer a = new Answer(id, ownerID, score, commentCount, date, parentID);
                this.tcd.addPost(a);
            } else {
                return;
            }


        }

    }
}






class UserParser extends DefaultHandler {

    private TCDCommunity tcd;


    public  UserParser(TCDCommunity tcd){
        this.tcd = tcd;
    }


    public void startElement(String namespaceURI, String localName, String qName, Attributes atts){
        String name;
        String about;
        long id;
        long reputation;
        List<Long> posts;

        if(atts.getLength() == 0) return;


        id = Long.parseLong(atts.getValue("Id"));
        about = atts.getValue("AboutMe");
        name = atts.getValue("DisplayName");
        reputation = Long.parseLong(atts.getValue("Reputation"));

        User u = new User(name, about, id, reputation);
        this.tcd.addUser(u);



    }

}




class TagParser extends DefaultHandler {

    private TCDCommunity tcd;


    public TagParser(TCDCommunity tcd) {
        this.tcd = tcd;
    }


    public void startElement(String namespaceURI, String localName, String qName, Attributes atts) {
        String name;
        long id;

        if(atts.getLength() == 0) return;

        id = Long.parseLong(atts.getValue("Id"));
        name = atts.getValue("TagName");

        Tag t = new Tag(id, name);
        this.tcd.addTag(t);


    }
}