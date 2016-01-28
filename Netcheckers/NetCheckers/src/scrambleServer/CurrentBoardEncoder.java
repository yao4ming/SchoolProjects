package scrambleServer;


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
public class CurrentBoardEncoder implements Encoder.Text<CurrentBoard> {
    @Override
    public void init(EndpointConfig endpointConfig) {

    }

    @Override
    public void destroy() {

    }

    /**
     * NEW
     * use jaxb to marshal java object to xml
     * @param board - java obj to marshal
     * @return xml as string
     * @throws javax.websocket.EncodeException
     */
    @Override
    public String encode(CurrentBoard board) throws EncodeException {
        StringWriter buffer = null;
        try{
            buffer = new StringWriter();
            JAXBContext jaxbContext = JAXBContext.newInstance(CurrentBoard.class);
            Marshaller marshaller = jaxbContext.createMarshaller();

            //marshal board obj to xml and store in buffer
            marshaller.marshal(board ,buffer);
            //System.out.println(buffer.toString());

        } catch (JAXBException e) {
            e.printStackTrace();
        }
        return buffer.toString();
    }
}
