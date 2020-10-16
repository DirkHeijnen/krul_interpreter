#include <gtest/gtest.h>
#include <HttpClient.hpp>

class HttpClientTests : public ::testing::Test
{
    public:
        HttpClientTests() { }
};

TEST_F(HttpClientTests, Test_Get_Request_Contains_Content_Body)
{
    HttpClient client = HttpClient();
    HttpResponse response = client.get("https://jsonplaceholder.typicode.com/posts/1");

    ASSERT_TRUE(response.body.size() > 1);
    ASSERT_TRUE(response.statusCode == HttpStatusCode::OK);
}

TEST_F(HttpClientTests, Test_StatusCode_Mapping_From_Number)
{
    HttpStatusCode okStatus = HttpStatusCode(200);
    HttpStatusCode badRequestStatus = HttpStatusCode(400);
    HttpStatusCode notFoundStatus = HttpStatusCode(404);

    ASSERT_EQ(okStatus, HttpStatusCode::OK);
    ASSERT_EQ(badRequestStatus, HttpStatusCode::BAD_REQUEST);
    ASSERT_EQ(notFoundStatus, HttpStatusCode::NOT_FOUND);
}

TEST_F(HttpClientTests, Test_StatusCode_Mapping_From_Code)
{
    HttpStatusCode okStatus = HttpStatusCode::OK;
    HttpStatusCode badRequestStatus = HttpStatusCode::BAD_REQUEST;
    HttpStatusCode notFoundStatus =HttpStatusCode::NOT_FOUND;

    ASSERT_EQ(okStatus, 200);
    ASSERT_EQ(badRequestStatus, 400);
    ASSERT_EQ(notFoundStatus, 404);
}