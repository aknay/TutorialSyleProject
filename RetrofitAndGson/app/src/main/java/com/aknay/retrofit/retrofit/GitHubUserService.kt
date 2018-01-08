package com.aknay.retrofit.retrofit

object GitHubUserService {
    val gitHubService: GitHubApiRoutes
        get() = RetrofitClient.client.create(GitHubApiRoutes::class.java)
}