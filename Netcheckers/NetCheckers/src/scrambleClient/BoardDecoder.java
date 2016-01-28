package scrambleClient;

import scrambleServer.CurrentBoard;

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
public class BoardDecoder implements Decoder.Text<CurrentBoard> {

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
    public CurrentBoard decode(String s) throws DecodeException {
        //System.out.println("Incoming XML: " + s);
        CurrentBoard currentBoard = null;
        JAXBContext jaxbContext = null;
        try{
            jaxbContext = JAXBContext.newInstance(CurrentBoard.class);
            Unmarshaller unmarshaller = jaxbContext.createUnmarshaller();
            StringReader reader = new StringReader(s);
            currentBoard = (CurrentBoard) unmarshaller.unmarshal(reader);
        } catch (JAXBException e) {
            e.printStackTrace();
        }

        return currentBoard;
    }

    /**
     * NEW
     * checks to see if there is any XML to decode
     * @param s XML to decode
     * @return true - XML was present
     *         false - NO XML
     */
    @Override
    public boolean willDecode(String s) {
        return (s != null);
    }
}
