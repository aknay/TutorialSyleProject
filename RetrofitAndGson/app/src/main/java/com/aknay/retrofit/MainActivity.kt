package com.aknay.retrofit

import android.os.Bundle
import android.support.v7.app.AppCompatActivity
import android.widget.Button
import android.widget.EditText
import android.widget.TextView
import com.aknay.mRetrofit.R
import com.aknay.retrofit.model.GitHubUser
import com.aknay.retrofit.retrofit.GitHubApiRoutes
import com.aknay.retrofit.retrofit.GitHubUserService
import retrofit2.Call
import retrofit2.Callback
import retrofit2.Response

class MainActivity : AppCompatActivity() {

    private var mGitHubApiRoutes: GitHubApiRoutes? = null

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        mGitHubApiRoutes = GitHubUserService.gitHubService
        findViewById<Button>(R.id.button).setOnClickListener {
            val userName = findViewById<EditText>(R.id.editText)!!.text.toString()
            getUser(userName)
        }
    }

    private fun getUser(userName: String) {
        mGitHubApiRoutes!!.getUser(userName).enqueue(object : Callback<GitHubUser> {
            override fun onResponse(call: Call<GitHubUser>, response: Response<GitHubUser>) {
                if (response.isSuccessful) {
                    val msg = "Number of repo is : " + response.body()?.publicRepos
                    setTextView(msg)
                } else {
                    setTextView("User may not exist")
                }
            }

            override fun onFailure(call: Call<GitHubUser>, t: Throwable) {
                setTextView("Fail to call")
            }

        })
    }

    private fun setTextView(text: String) {
        findViewById<TextView>(R.id.textView)!!.text = text
    }
}