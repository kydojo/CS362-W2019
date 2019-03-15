
// CS362 - Final Project - Part B
// Authors:     Shannon Lucas
//              Michael Morris
//              Kyle Johnson
// Due:         March 15, 2019
// Description: Test suite for the Apache Commons URL Validator program.
//              Manual testing, programmatic testing, and random testing methods
//              are all included in the suite.

import junit.framework.TestCase;
import java.util.Random;

public class UrlValidatorTest extends TestCase {

    // Class constructor
    public UrlValidatorTest(String testName) {

        // Call the constructor of the parent class (TestCase)
        super(testName);
    }


    // Method to assert that a valid URL passes the test and returns that it's valid
    public static void assertTrue(String url, boolean isValidUrl){
        if(isValidUrl){
            System.out.println("URL: " + url + "\tExpected: VALID\tResult: VALID\t\tPASSED");
        }
        else{
            System.out.println("URL: " + url + "\tExpected: VALID\tResult: INVALID\t\tFAILED");
        }
    }


    // Method to assert that an invalid URL passes the test and returns that it's invalid
    public static void assertFalse(String url, boolean isValidUrl){
        if(!isValidUrl){
            System.out.println("URL: " + url + "\tExpected: INVALID\tResult: INVALID\t\tPASSED");
        }
        else{
            System.out.println("URL: " + url + "\tExpected: INVALID\tResult: VALID\t\tFAILED");
        }
    }

    // Method that manually pre-constructs URLs to be tested and validates their testing
    public void testManualTest(){

        // local urls validator below
        System.out.println("Allow Local URLs UrlValidator\n\n");
        UrlValidator urlLocal = new UrlValidator(null, null, UrlValidator.ALLOW_LOCAL_URLS);

        // test valid and invalid schemes, authority, ports, and path options

        System.out.println("======================================================\n");
        System.out.println("Testing SCHEMES below:\n");

        // valid URL scheme
        String validScheme1 = "http://www.google.com";
        String validScheme2 = "http://www.facebook.com";
        String validScheme3 = "ftp://www.amazon.com";

        System.out.println("Testing scheme for url: " + validScheme1 + ". Expected to return TRUE");
        System.out.println(urlLocal.isValid(validScheme1));
        System.out.println("Testing scheme for url: " + validScheme2 + ". Expected to return TRUE");
        System.out.println(urlLocal.isValid(validScheme2));
        System.out.println("Testing scheme for url: " + validScheme3 + ". Expected to return TRUE");
        System.out.println(urlLocal.isValid(validScheme3));

        // invalid URL schemes
        String invalidScheme1 = "http:www.google.com";
        String invalidScheme2 = "http:/www.facebook.com";
        String invalidScheme3 = "://www.amazon.com";

        System.out.println("Testing scheme for url: " + invalidScheme1 + ". Expected to return FALSE");
        System.out.println(urlLocal.isValid(invalidScheme1));
        System.out.println("Testing scheme for url: " + invalidScheme2 + ". Expected to return FALSE");
        System.out.println(urlLocal.isValid(invalidScheme2));
        System.out.println("Testing scheme for url: " + invalidScheme3 + ". Expected to return FALSE");
        System.out.println(urlLocal.isValid(invalidScheme3));


        System.out.println("======================================================\n");
        System.out.println("Testing AUTHORITY below:\n");

        // valid URL authority
        String validAuth1 = "1.2.3.4";
        String validAuth2 = "www.google.com";
        String validAuth3 = "www.twitter.com";

        System.out.println("Testing authority for url: " + validAuth1 + ". Expected to return TRUE");
        System.out.println(urlLocal.isValid(validAuth1));
        System.out.println("Testing authority for url: " + validAuth2 + ". Expected to return TRUE");
        System.out.println(urlLocal.isValid(validAuth2));
        System.out.println("Testing authority for url: " + validAuth3 + ". Expected to return TRUE");
        System.out.println(urlLocal.isValid(validAuth3));

        // invalid URL authority
        String invalidAuth1 = "";
        String invalidAuth2 = "http://www.google.com"; // i think the http should mess this up

        System.out.println("Testing authority for url: " + invalidAuth1 + ". Expected to return FALSE");
        System.out.println(urlLocal.isValid(invalidAuth1));
        System.out.println("Testing authority for url: " + invalidAuth2 + ". Expected to return FALSE");
        System.out.println(urlLocal.isValid(invalidAuth2));

        System.out.println("======================================================\n");
        System.out.println("Testing PORTS below:\n");

        // valid URL port
        String validPort1 = "http://www.google.com:80";
        String validPort2 = "http://twitter.com:8080";
        String validPort3 = "http://facebook.com:1234";
        String validPort4 = "http://www.google.com";

        System.out.println("Testing ports for url: " + validPort1 + ". Expected to return TRUE");
        System.out.println(urlLocal.isValid(validPort1));
        System.out.println("Testing ports for url: " + validPort2 + ". Expected to return TRUE");
        System.out.println(urlLocal.isValid(validPort2));
        System.out.println("Testing ports for url: " + validPort3 + ". Expected to return TRUE");
        System.out.println(urlLocal.isValid(validPort3));
        System.out.println("Testing ports for url: " + validPort4 + ". Expected to return TRUE");
        System.out.println(urlLocal.isValid(validPort4));

        //invalid URL port
        String invalidPort1 = "http://www.google.com:0";
        String invalidPort2 = "http://www.google.com:abc";
        String invalidPort3 = "http://www.google.com:-12";

        System.out.println("Testing ports for url: " + invalidPort1 + ". Expected to return FALSE");
        System.out.println(urlLocal.isValid(invalidPort1));
        System.out.println("Testing ports for url: " + invalidPort2 + ". Expected to return FALSE");
        System.out.println(urlLocal.isValid(invalidPort2));
        System.out.println("Testing ports for url: " + invalidPort3 + ". Expected to return FALSE");
        System.out.println(urlLocal.isValid(invalidPort3));

        System.out.println("======================================================\n");
        System.out.println("Testing PATHS below:\n");

        // valid URL path
        String validPath1 = "http://www.google.com/hi";
        String validPath2 = "http://www.google.com/123abc";
        String validPath3 = "http://www.google.com/123/abc";
        String validPath4 = "http://www.google.com";

        System.out.println("Testing paths for URL: " + validPath1 + ". Expected to return TRUE");
        System.out.println(urlLocal.isValid(validPath1));
        System.out.println("Testing paths for URL: " + validPath2 + ". Expected to return TRUE");
        System.out.println(urlLocal.isValid(validPath2));
        System.out.println("Testing paths for URL: " + validPath3 + ". Expected to return TRUE");
        System.out.println(urlLocal.isValid(validPath3));
        System.out.println("Testing paths for URL: " + validPath4 + ". Expected to return TRUE");
        System.out.println(urlLocal.isValid(validPath4));

        // invalid URL path
        String invalidPath1 = "http://www.google.com/..//hi";
        String invalidPath2 = "http://www.google.com/123///abc";
        String invalidPath3 = "http://www.google.com/../";

        System.out.println("Testing paths for URL: " + invalidPath1 + ". Expected to return FALSE");
        System.out.println(urlLocal.isValid(invalidPath1));
        System.out.println("Testing paths for URL: " + invalidPath2 + ". Expected to return FALSE");
        System.out.println(urlLocal.isValid(invalidPath2));
        System.out.println("Testing paths for URL: " + invalidPath3 + ". Expected to return FALSE");
        System.out.println(urlLocal.isValid(invalidPath3));

        System.out.println("======================================================\n");
        System.out.println("Testing QUERIES below:\n");

        // valid URL query
        String validQuery1 = "http://www.google.com?name=roonilwazlib";
        String validQuery2 = "http://www.google.com?class=361&stateofmind=dazedandconfused";
        String validQuery3 = "http://www.google.com";

        System.out.println("Testing queries for URL: " + validQuery1 + ". Expected to return TRUE");
        System.out.println(urlLocal.isValid(validQuery1));
        System.out.println("Testing queries for URL: " + validQuery2 + ". Expected to return TRUE");
        System.out.println(urlLocal.isValid(validQuery2));
        System.out.println("Testing queries for URL: " + validQuery3 + ". Expected to return TRUE");
        System.out.println(urlLocal.isValid(validQuery3));

        // invalid URL query
        String invalidQuery1 = "http://www.google.com????name=kyle";
        String invalidQuery2 = "http://www.google.com?name=";
        String invalidQuery3 = "http://www.google.com??";

        System.out.println("Testing queries for URL: " + invalidQuery1 + ". Expected to return FALSE");
        System.out.println(urlLocal.isValid(invalidQuery1));
        System.out.println("Testing queries for URL: " + invalidQuery2 + ". Expected to return FALSE");
        System.out.println(urlLocal.isValid(invalidQuery2));
        System.out.println("Testing queries for URL: " + invalidQuery3 + ". Expected to return FALSE");
        System.out.println(urlLocal.isValid(invalidQuery3));


        System.out.println("Ending --- Allow Local URLs UrlValidator\n\n");

        System.out.println("======================================================\n");

    }


    // Partitioning our inputs into the different components of the URL

    // Method to test URL scheme validation
    public void testYourFirstPartition(){

        System.out.println("\n======================================================");
        System.out.println("Testing URL Scheme Validation");
        System.out.println("======================================================");

        // Can't use ALLOW_ALL_SCHEMES here, since we're testing scheme validation
        //UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
        UrlValidator urlVal = new UrlValidator();

        // Testing valid schemes via custom assert functions that work via the built-in isValid() method
        assertTrue("http://www.oregonstate.edu", urlVal.isValid("http://www.oregonstate.edu"));
        assertTrue("https://www.oregonstate.edu", urlVal.isValid("https://www.oregonstate.edu"));
        assertTrue("ftp://www.oregonstate.edu", urlVal.isValid("ftp://www.oregonstate.edu"));
        assertTrue("h3t://www.oregonstate.edu", urlVal.isValid("h3t://www.oregonstate.edu"));

        // Testing invalid schemes via custom assert functions that work via the built-in isValid() method
        assertFalse("3ht://www.oregonstate.edu", urlVal.isValid("3ht://www.oregonstate.edu"));
        assertFalse("http:/www.oregonstate.edu", urlVal.isValid("http:/www.oregonstate.edu"));
        assertFalse("http:www.oregonstate.edu", urlVal.isValid("http:www.oregonstate.edu"));
        assertFalse("http/www.oregonstate.edu", urlVal.isValid("http/www.oregonstate.edu"));
        assertFalse("://www.oregonstate.edu", urlVal.isValid("://www.oregonstate.edu"));

    }

    // Method to test URL authority validation
    public void testYourSecondPartition(){

        System.out.println("\n======================================================");
        System.out.println("Testing URL Authority Validation");
        System.out.println("======================================================");

        UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

        // Testing valid authorities via custom assert functions that work via the built-in isValid() method
        assertTrue("http://go.com", urlVal.isValid("http://go.com"));
        assertTrue("http://go.au", urlVal.isValid("http://go.au"));
        assertTrue("http://0.0.0.0", urlVal.isValid("http://0.0.0.0"));
        assertTrue("http://255.255.255.255", urlVal.isValid("http://255.255.255.255"));
        assertTrue("http://255.com", urlVal.isValid("http://255.com"));

        // Testing invalid authorities via custom assert functions that work via the built-in isValid() method
        assertFalse("http://256.256.256.256", urlVal.isValid("http://256.256.256.256"));
        assertFalse("http://1.2.3.4.5", urlVal.isValid("http://1.2.3.4.5"));
        assertFalse("http://1.2.3.4.", urlVal.isValid("http://1.2.3.4."));
        assertFalse("http://1.2.3", urlVal.isValid("http://1.2.3"));
        assertFalse("http://.1.2.3.4", urlVal.isValid("http://.1.2.3.4"));
        assertFalse("http://go.a", urlVal.isValid("http://go.a"));
        assertFalse("http://go.ala", urlVal.isValid("http://go.ala"));
        assertFalse("http://go.laa", urlVal.isValid("http://go.laa"));
        assertFalse("http://aaa.", urlVal.isValid("http://aaa."));
        assertFalse("http://.aaa", urlVal.isValid("http://.aaa"));
        assertFalse("http://aaa", urlVal.isValid("http://aaa"));
        assertFalse("http://", urlVal.isValid("http://"));

    }


    // Method to test URL port validation
    public void testYourThirdPartition(){

        System.out.println("\n======================================================");
        System.out.println("Testing URL Port Validation");
        System.out.println("======================================================");

        UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

        // Testing valid ports via custom assert functions that work via the built-in isValid() method
        assertTrue("http://www.oregonstate.edu:80", urlVal.isValid("http://www.oregonstate.edu:80"));
        assertTrue("http://www.oregonstate.edu:65535", urlVal.isValid("http://www.oregonstate.edu:65535"));
        assertTrue("http://www.oregonstate.edu", urlVal.isValid("http://www.oregonstate.edu"));

        // Testing invalid ports via custom assert functions that work via the built-in isValid() method
        assertFalse("http://www.oregonstate.edu:-1", urlVal.isValid("3ht://www.oregonstate.edu:-1"));
        assertFalse("http://www.oregonstate.edu:65636", urlVal.isValid("3ht://www.oregonstate.edu:65636"));
        assertFalse("http://www.oregonstate.edu:65a", urlVal.isValid("3ht://www.oregonstate.edu:65a"));

    }


    // Method to test URL path validation
    public void testYourFourthPartition(){

        System.out.println("\n======================================================");
        System.out.println("Testing URL Path Validation");
        System.out.println("======================================================");

        UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

        // Testing valid paths via custom assert functions that work via the built-in isValid() method
        assertTrue("http://www.oregonstate.edu/test1", urlVal.isValid("http://www.oregonstate.edu/test1"));
        assertTrue("http://www.oregonstate.edu/t123", urlVal.isValid("http://www.oregonstate.edu/t123"));
        assertTrue("http://www.oregonstate.edu/$23", urlVal.isValid("http://www.oregonstate.edu/$23"));
        assertTrue("http://www.oregonstate.edu/test1/", urlVal.isValid("http://www.oregonstate.edu/test1/"));
        assertTrue("http://www.oregonstate.edu", urlVal.isValid("http://www.oregonstate.edu"));
        assertTrue("http://www.oregonstate.edu/test1/file", urlVal.isValid("http://www.oregonstate.edu/test1/file"));

        // Testing invalid paths via custom assert functions that work via the built-in isValid() method
        assertFalse("http://www.oregonstate.edu/..", urlVal.isValid("3ht://www.oregonstate.edu/.."));
        assertFalse("http://www.oregonstate.edu/../", urlVal.isValid("3ht://www.oregonstate.edu/../"));
        assertFalse("http://www.oregonstate.edu/..//file", urlVal.isValid("3ht://www.oregonstate.edu/..//file"));
        assertFalse("http://www.oregonstate.edu/test1//file", urlVal.isValid("3ht://www.oregonstate.edu/test1//file"));

    }


    // Method to test URL query validation
    public void testYourFifthPartition(){

        System.out.println("\n======================================================");
        System.out.println("Testing URL Query Validation");
        System.out.println("======================================================");

        UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

        // Testing valid queries via custom assert functions that work via the built-in isValid() method
        assertTrue("http://www.oregonstate.edu?action=view", urlVal.isValid("http://www.oregonstate.edu?action=view"));
        assertTrue("http://www.oregonstate.edu?action=edit&mode=up", urlVal.isValid("http://www.oregonstate.edu?action=edit&mode=up"));
        assertTrue("http://www.oregonstate.edu", urlVal.isValid("http://www.oregonstate.edu"));

    }


    // Method to test isValid() built-in method
    public void testIsValid(){
        System.out.println("\n\n======================================================");
        System.out.println("Testing random components of the ResultPair[] objects concatenated together");
        System.out.println("======================================================\n");

        // create a random variable for url: assigning a random portion of the url
        Random rand = new Random();

        // UrlValidator object instantiation with no fragments
        UrlValidator url = new UrlValidator(null, null, UrlValidator.NO_FRAGMENTS);

        // create MAX VALS to generate random strings from the ResultPair[] url array of objects
        // index starts at 0, so max number == Length(ResultPair[]) - 1
        int urlSchemeMax = 8;
        int urlAuthorityMax = 17;
        int urlPortMax = 6;
        int urlPathMax = 9;
        int urlQueryMax = 2; // using urlvalidator with no fragments, so a max var for url: that section is not needed
        int numTests = 50;

        for(int i = 0; i < numTests; i++){

            int urlIndex; // used to store a random number for url: each url portion

            // strings immutable in java so need to combined all portions of the url before converting to string
            StringBuilder concattedUrl = new StringBuilder();

            // add a random component of testUrlScheme
            urlIndex = rand.nextInt(urlSchemeMax);
            concattedUrl.append(testUrlScheme[urlIndex].item);

            // add a random component of testUrlAuthority
            urlIndex = rand.nextInt(urlAuthorityMax);
            concattedUrl.append(testUrlAuthority[urlIndex].item);

            // add a random component of testUrlPort
            urlIndex = rand.nextInt(urlPortMax);
            concattedUrl.append(testUrlPort[urlIndex].item);

            // add a random component of testPath
            urlIndex = rand.nextInt(urlPathMax);
            concattedUrl.append(testPath[urlIndex].item);

            // add a random component of testUrlQuery
            urlIndex = rand.nextInt(urlQueryMax);
            concattedUrl.append(testUrlQuery[urlIndex].item);

            // create the string for url: printing
            String finalUrl = concattedUrl.toString();

            System.out.println("======================================================");
            System.out.println("Created the following random URL string: \t " + finalUrl);
            System.out.println("Calling isValid() function: ");

            boolean isValidURL = url.isValid(finalUrl);

            if(isValidURL) {
                System.out.println("URL is VALID");
            }
            else {
                System.out.println("URL is NOT VALID");
            }
        }
    }


    // Result pairs from Apache's UrlValidatorTest.java file

    ResultPair[] testUrlScheme = {new ResultPair("http://", true),
            new ResultPair("ftp://", true),
            new ResultPair("h3t://", true),
            new ResultPair("3ht://", false),
            new ResultPair("http:/", false),
            new ResultPair("http:", false),
            new ResultPair("http/", false),
            new ResultPair("://", false),
            new ResultPair("", true)};


    ResultPair[] testUrlAuthority = {new ResultPair("www.google.com", true),
            new ResultPair("go.com", true),
            new ResultPair("go.au", true),
            new ResultPair("0.0.0.0", true),
            new ResultPair("255.255.255.255", true),
            new ResultPair("256.256.256.256", false),
            new ResultPair("255.com", true),
            new ResultPair("1.2.3.4.5", false),
            new ResultPair("1.2.3.4.", false),
            new ResultPair("1.2.3", false),
            new ResultPair(".1.2.3.4", false),
            new ResultPair("go.a", false),
            new ResultPair("go.a1a", false),
            new ResultPair("go.1aa", false),
            new ResultPair("aaa.", false),
            new ResultPair(".aaa", false),
            new ResultPair("aaa", false),
            new ResultPair("", false)
    };
    ResultPair[] testUrlPort = {new ResultPair(":80", true),
            new ResultPair(":65535", true),
            new ResultPair(":0", true),
            new ResultPair("", true),
            new ResultPair(":-1", false),
            new ResultPair(":65636",false),
            new ResultPair(":65a", false)
    };


    ResultPair[] testPath = {new ResultPair("/test1", true),
            new ResultPair("/t123", true),
            new ResultPair("/$23", true),
            new ResultPair("/..", false),
            new ResultPair("/../", false),
            new ResultPair("/test1/", true),
            new ResultPair("", true),
            new ResultPair("/test1/file", true),
            new ResultPair("/..//file", false),
            new ResultPair("/test1//file", false)
    };


    ResultPair[] testUrlPathOptions = {new ResultPair("/test1", true),
            new ResultPair("/t123", true),
            new ResultPair("/$23", true),
            new ResultPair("/..", false),
            new ResultPair("/../", false),
            new ResultPair("/test1/", true),
            new ResultPair("/#", false),
            new ResultPair("", true),
            new ResultPair("/test1/file", true),
            new ResultPair("/t123/file", true),
            new ResultPair("/$23/file", true),
            new ResultPair("/../file", false),
            new ResultPair("/..//file", false),
            new ResultPair("/test1//file", true),
            new ResultPair("/#/file", false)
    };


    ResultPair[] testUrlQuery = {new ResultPair("?action=view", true),
            new ResultPair("?action=edit&mode=up", true),
            new ResultPair("", true)
    };


    Object[] testUrlParts = {testUrlScheme, testUrlAuthority, testUrlPort, testPath, testUrlQuery};
    Object[] testUrlPartsOptions = {testUrlScheme, testUrlAuthority, testUrlPort, testUrlPathOptions, testUrlQuery};
    int[] testPartsIndex = {0, 0, 0, 0, 0};

    //---------------- Test data for url: individual url parts ----------------
    ResultPair[] testScheme = {new ResultPair("http", true),
            new ResultPair("ftp", false),
            new ResultPair("httpd", false),
            new ResultPair("telnet", false)};

}
