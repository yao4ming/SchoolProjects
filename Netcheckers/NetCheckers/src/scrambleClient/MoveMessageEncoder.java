package scrambleClient;

import javax.websocket.EncodeException;
import javax.websocket.Encoder;
import javax.websocket.EndpointConfig;
import javax.xml.bind.JAXBContext;
import javax.xml.bind.JAXBException;
import javax.xml.bind.Marshaller;
import java.io.StringWriter;

/**
 * Class to encode java object to XML
 */
public class MoveMessageEncoder implements Encoder.Text<MoveMessage> {

    /**
     * NEW
     * use jaxb to marshal java object to xml
     * @param message - java obj to marshal
     * @return xml as string
     * @throws javax.websocket.EncodeException
     */
    @Override
    public String encode(MoveMessage message) throws EncodeException {
        StringWriter buffer = null;
        try{
            buffer = new StringWriter();
            JAXBContext jaxbContext = JAXBContext.newInstance(MoveMessage.class);
            Marshaller marshaller = jaxbContext.createMarshaller();

            //marshal move obj to xml and store in buffer
            marshaller.marshal(message ,buffer);
            //System.out.println(buffer.toString());

        } catch (JAXBException e) {
            e.printStackTrace();
        }
        return buffer.toString();
    }

    @Override
    public void init(EndpointConfig endpointConfig) {

    }

    @Override
    public void destroy() {

    }
}
