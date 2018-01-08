package com.aknay.retrofit.retrofit

import com.aknay.retrofit.model.GitHubUser

import retrofit2.Call
import retrofit2.http.GET
import retrofit2.http.Path

interface GitHubApiRoutes {
    @GET("/users/{username}")
    fun getUser(@Path("username") username: String): Call<GitHubUser>
}