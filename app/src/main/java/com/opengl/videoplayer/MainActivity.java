package com.opengl.videoplayer;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.TextView;

import com.opengl.videoplayer.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

    static {
        System.loadLibrary("native-lib");
        System.loadLibrary("avformat");
        System.loadLibrary("avfilter");
        System.loadLibrary("avcodec");
        System.loadLibrary("avutil");
        System.loadLibrary("avdevice");
        System.loadLibrary("swresample");
        System.loadLibrary("swscale");
    }
    private ActivityMainBinding binding;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());
        TextView tv = binding.sampleText;
        tv.setText(stringFromJNI());
    }
    public native String stringFromJNI();
}