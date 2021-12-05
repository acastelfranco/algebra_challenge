#pragma once

#include <map>
#include <string>
#include <vector>
#include <Raceway.h>

namespace utils {
    namespace math {
        /**
         * @brief Returns whether two numbers are close within an epsilon.
         * 
         * @param a 
         * @param b 
         * @param epsilon 
         * @return true 
         * @return false 
         */

        bool
        close(double a, double b, double epsilon = 1e-4);
    }

    namespace testdata {
        /**
         * @brief Structure to help in writing hard-coded tests of support computation.
         */
        struct TestEndpoint
        {
            std::string name;
            double x;
            double y;
            double z;
        };

        /**
         * @brief Structure to help in writing hard-coded tests of support computation.
         */
        struct TestSegment
        {
            std::string name;
            std::string start_name;
            std::string end_name;
        };

        /**
         * @brief Structure for hard-coding test data for support computation.
         * Endpoints and segments can be defined as data and can be assigned
         * names which are useful for testing the results of the support
         * computation.  This class can create a Raceway from the hard-coded
         * endpoints and segment vectors.
         */
        struct TestData
        {
            using NamedEndpoints = std::map<std::string, Endpoint_H>;
            using NamedSegments = std::map<std::string, Segment_H>;
            
            std::vector<TestEndpoint> endpoints;
            std::vector<TestSegment> segments;

            /**
             * @brief Populate a Raceway object from the hard-coded test data.  Also returns
             * maps of the testing names for the endpoint/segment objects that were
             * added into the raceway.
             * 
             * @param raceway 
             * @param eps 
             * @param segs 
             */
            void populate(Raceway& raceway, NamedEndpoints& eps, NamedSegments& segs);
        };
    }
}