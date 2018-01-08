package com.aknay.retrofit.retrofit

import retrofit2.Retrofit
import retrofit2.converter.gson.GsonConverterFactory

object RetrofitClient {

    private var mRetrofit: Retrofit? = null
    private val BASE_URL = "https://api.github.com/"
    val client: Retrofit
        get() {
            if (mRetrofit == null) {
                return Retrofit.Builder()
                        .baseUrl(BASE_URL)
                        .addConverterFactory(GsonConverterFactory.create())
                        .build()
            }
            return mRetrofit!!
        }
}