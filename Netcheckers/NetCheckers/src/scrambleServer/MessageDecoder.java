package scrambleServer;

import scrambleClient.Message;
import scrambleClient.MoveMessage;
import javax.websocket.DecodeException;
import javax.websocket.Decoder;
import javax.websocket.EndpointConfig;
import javax.xml.bind.JAXBContext;
import javax.xml.bind.JAXBException;
import javax.xml.bind.Unmarshaller;
import java.io.StringReader;

/**
 * NEW
 * Class decodes the current state of the board represented in XML to a java object
 */
public class MessageDecoder implements Decoder.Text<Message> {

    @Override
    public void init(EndpointConfig endpointConfig) {

    }

    @Override
    public void destroy() {

    }

    /**
     * NEW
     * Use jaxb to unmarshal the xml to java object
     * @param s - XML to decode
     * @return decoded java object
     * @throws javax.websocket.DecodeException
     */
    @Override
    public Message decode(String s) throws DecodeException {
        //System.out.println(s);
        Message message = null;
        try{
            JAXBContext jaxbContext = JAXBContext.newInstance(MoveMessage.class);
            Unmarshaller unmarshaller = jaxbContext.createUnmarshaller();
            StringReader reader = new StringReader(s);
            message = (Message) unmarshaller.unmarshal(reader);

        } catch (JAXBException e) {
            e.printStackTrace();
        }
        return message;
    }

    @Override
    public boolean willDecode(String s) {
        return (s != null);
    }
}
