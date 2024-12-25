import java.net.InetAddress;
import java.net.UnknownHostException;

public class ObtenirAdresseIPv4Locale {
    public static String obtenirAdresseIPv4Locale() {
        try {
            InetAddress inetAddress = InetAddress.getLocalHost();
            return inetAddress.getHostAddress();
        } catch (UnknownHostException e) {
            return e.getMessage();
        }
    }

    public static void main(String[] args) {
        String adresseIPv4Locale = obtenirAdresseIPv4Locale();
        System.out.println("Adresse IPv4 Locale: " + adresseIPv4Locale);
    }
}
