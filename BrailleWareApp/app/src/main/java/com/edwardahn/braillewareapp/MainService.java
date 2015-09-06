package com.edwardahn.braillewareapp;

import android.app.Service;
import android.content.Intent;
import android.os.IBinder;
import android.widget.Toast;

import org.apache.http.params.HttpParams;
import org.apache.http.protocol.HTTP;

import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.URL;
import java.net.HttpURLConnection;

// we're going to use this service to send and receive data from internet
public class MainService extends Service {
    public MainService() {

    }

    @Override
    public IBinder onBind(Intent intent) {
        return null;
        // TODO: Return the communication channel to the service.
        //throw new UnsupportedOperationException("Not yet implemented");
    }

    @Override
    public void onCreate() {
        super.onCreate();
        Toast.makeText(this, "Service created ...", Toast.LENGTH_LONG).show();
        new Thread(new Runnable() {

            URL url;
            HttpURLConnection urlConnection;
            public void run() {
                try {
                    url = new URL("http://boilerpipe-web.appspot.com/extract?url=http://google.com&extractor=ArticleExtractor&output=json");
                    urlConnection = (HttpURLConnection) url.openConnection();
                    BufferedReader in = new BufferedReader(new InputStreamReader(
                            urlConnection.getInputStream()));
                    String inputLine;
                    while ((inputLine = in.readLine()) != null)
                        System.out.println(inputLine);
                } catch (Exception e) {
                } finally {
                    urlConnection.disconnect();
                }

                while (true) {
                    Intent intent = new Intent(Constants.SEND_STRING);
                    sendBroadcast(intent);
                    try {
                        Thread.sleep(10 * 1000);
                    } catch (Exception e) {
                    }
                }
            }
        }).start();
    }


}
