from feature import RectangleRegion, HaarFeature
from classifier import WeakClassifier
import utils
import numpy as np
import math
from sklearn.feature_selection import SelectPercentile, f_classif
import pickle

class Adaboost:
    def __init__(self, T = 10):
        """
          Parameters:
            T: The number of weak classifiers which should be used.
        """
        self.T = T
        self.alphas = []
        self.clfs = []

    def train(self, dataset):
        """
        Trains the Viola Jones classifier on a set of images.
          Parameters:
            dataset: A list of tuples. The first element is the numpy 
              array with shape (m, n) representing the image. The second
              element is its classification (1 or 0).
        """
        print("Computing integral images")
        posNum, negNum = 0, 0
        iis, labels = [], []
        for i in range(len(dataset)):
            iis.append(utils.integralImage(dataset[i][0]))
            labels.append(dataset[i][1])
            if dataset[i][1] == 1:
                posNum += 1
            else:
                negNum += 1
        print("Building features")
        features = self.buildFeatures(iis[0].shape)
        print("Applying features to dataset")
        featureVals = self.applyFeatures(features, iis)
        print("Selecting best features")
        indices = SelectPercentile(f_classif, percentile=10).fit(featureVals.T, labels).get_support(indices=True)
        featureVals = featureVals[indices]
        features = features[indices]
        print("Selected %d potential features" % len(featureVals))
        
        print("Initialize weights")
        weights = np.zeros(len(dataset))
        for i in range(len(dataset)):
            if labels[i] == 1:
                weights[i] = 1.0 / (2 * posNum)
            else:
                weights[i] = 1.0 / (2 * negNum)
        for t in range(self.T):
            print("Run No. of Iteration: %d" % (t+1))
            # Normalize weights
            weights = weights / np.sum(weights)
            # Compute error and select best classifiers
            clf, error = self.selectBest(featureVals, iis, labels, features, weights)
            #update weights
            accuracy = []
            for x, y in zip(iis, labels):
                correctness = abs(clf.classify(x) - y)
                accuracy.append(correctness)
            beta = error / (1.0 - error)
            for i in range(len(accuracy)):
                weights[i] = weights[i] * (beta ** (1 - accuracy[i]))
            alpha = math.log(1.0/beta)
            self.alphas.append(alpha)
            self.clfs.append(clf)
            print("Chose classifier: %s with accuracy: %f and alpha: %f" % (str(clf), len(accuracy) - sum(accuracy), alpha))
    
    def buildFeatures(self, imageShape):
        """
        Builds the possible features given an image shape.
          Parameters:
            imageShape: A tuple of form (height, width).
          Returns:
            A numpy array of HaarFeature class.
        """
        height, width = imageShape
        features = []
        for w in range(1, width+1):
            for h in range(1, height+1):
                i = 0
                while i + w < width:
                    j = 0
                    while j + h < height:
                        #2 rectangle features
                        immediate = RectangleRegion(i, j, w, h)
                        right = RectangleRegion(i+w, j, w, h)
                        if i + 2 * w < width: #Horizontally Adjacent
                            features.append(HaarFeature([right], [immediate]))

                        bottom = RectangleRegion(i, j+h, w, h)
                        if j + 2 * h < height: #Vertically Adjacent
                            features.append(HaarFeature([immediate], [bottom]))
                        
                        right_2 = RectangleRegion(i+2*w, j, w, h)
                        #3 rectangle features
                        if i + 3 * w < width: #Horizontally Adjacent
                            features.append(HaarFeature([right], [right_2, immediate]))

                        bottom_2 = RectangleRegion(i, j+2*h, w, h)
                        if j + 3 * h < height: #Vertically Adjacent
                            features.append(HaarFeature([bottom], [bottom_2, immediate]))

                        #4 rectangle features
                        bottom_right = RectangleRegion(i+w, j+h, w, h)
                        if i + 2 * w < width and j + 2 * h < height:
                            features.append(HaarFeature([right, bottom], [immediate, bottom_right]))

                        j += 1
                    i += 1
        return np.array(features)
    
    def applyFeatures(self, features, iis):
        """
        Maps features onto the training dataset.
          Parameters:
            features: A numpy array of HaarFeature class.
            iis: A list of numpy array with shape (m, n) representing the integral images.
          Returns:
            featureVals: A numpy array of shape (len(features), len(dataset)).
              Each row represents the values of a single feature for each training sample.
        """
        featureVals = np.zeros((len(features), len(iis)))
        for j in range(len(features)):
            for i in range(len(iis)):
                featureVals[j, i] = features[j].computeFeature(iis[i])
        return featureVals

    def selectBest(self, featureVals, iis, labels, features, weights):
        """
        Finds the appropriate weak classifier for each feature.
        Selects the best weak classifier for the given weights.
          Parameters:
            featureVals: A numpy array of shape (len(features), len(dataset)).
              Each row represents the values of a single feature for each training sample.
            iis: A list of numpy array with shape (m, n) representing the integral images.
            labels: A list of integer.
              The ith element is the classification of the ith training sample.
            features: A numpy array of HaarFeature class.
            weights: A numpy array with shape(len(dataset)).
              The ith element is the weight assigned to the ith training sample.
          Returns:
            bestClf: The best WeakClassifier Class
            bestError: The error of the best classifer
        """
        # Begin your code (Part 2)
        # raise NotImplementedError("To be implemented")
        # End your code (Part 2)

        featureNum = featureVals.shape[0]
        dataNum = featureVals.shape[1]
        weaks = []

        # Use feature to establish classifier woth polarity 1,-1
        


        # For each feature , create classifier, negative and positive
        print(str(featureNum) + ' features')
        for i in range(featureNum):
            for j in range(dataNum):
                weakclf_neg = WeakClassifier(features[i],featureVals[i][j],-1)
                weakclf_pos = WeakClassifier(features[i],featureVals[i][j],1)
                weaks.append(weakclf_neg)
                weaks.append(weakclf_pos)
    
        bestError = 1
        print(str(len(weaks)) + ' classifiers')
        for i in range(len(weaks)):
            result = []
            for k in range(dataNum):              
              result.append(weaks[i].classify(iis[k]))
            miss = [int(l!=m) for l, m in zip(result, labels)]
            error = np.dot(weights, miss)
            if error < bestError: 
              bestError = error
              bestClf = weaks[i]
        return bestClf, bestError
    
    # not test yet
    def custom_selectBest_v3(self, featureVals, iis, labels, features, weights): 
        """
        Finds the appropriate weak classifier for each feature.
        Selects the best weak classifier for the given weights.
          Parameters:
            featureVals: A numpy array of shape (len(features), len(dataset)).
              Each row represents the values of a single feature for each training sample.
            iis: A list of numpy array with shape (m, n) representing the integral images.
            labels: A list of integer.
              The ith element is the classification of the ith training sample.
            features: A numpy array of HaarFeature class.
            weights: A numpy array with shape(len(dataset)).
              The ith element is the weight assigned to the ith training sample.
          Returns:
            bestClf: The best WeakClassifier Class
            bestError: The error of the best classifer
        """
        # Begin your code (Part 2)
        # raise NotImplementedError("To be implemented")
        # End your code (Part 2)

        featureNum = featureVals.shape[0]
        dataNum = featureVals.shape[1]
        weaks = []

        # For each feature , create classifier, negative and positive
        print(str(featureNum) + ' features')
        for i in range(featureNum):
            for j in range(dataNum):
                weakclf_neg = WeakClassifier(features[i],featureVals[i][j],-1)
                weakclf_pos = WeakClassifier(features[i],featureVals[i][j],1)
                weaks.append(weakclf_neg) 
                weaks.append(weakclf_pos)
    
        bestError = 1
        print(str(len(weaks)) + ' classifiers')
        for i in range(len(weaks)):
            result = []
            for k in range(dataNum):              
              result.append(weaks[i].classify(iis[k]))
            miss = [int(l!=m) for l, m in zip(result, labels)]
            error = np.dot(weights, miss)
            if error < bestError: 
              bestError = error
              bestClf = weaks[i]
        return bestClf, bestError
    
    # 0.720
    def custom_selectBest_v2(self, featureVals, iis, labels, features, weights): 
        featureNum = featureVals.shape[0]
        dataNum = featureVals.shape[1]

        errors = []
        weaks = []

        # For each feature , create two classifier, negative and positive
        for i in range(featureNum):
            result_neg = []
            result_pos = []
            weakclf_neg = WeakClassifier(features[i],0,-1)
            weakclf_pos = WeakClassifier(features[i],0,1)
            for j in range(dataNum):
                result_neg.append(weakclf_neg.classify(iis[j]))
                result_pos.append(weakclf_pos.classify(iis[j]))
            miss_neg = [int(l!=m) for l, m in zip(result_neg, labels)]
            miss_pos = [int(l!=m) for l, m in zip(result_pos, labels)]
            error_neg = np.dot(weights, miss_neg)
            error_pos = np.dot(weights, miss_pos)

            if error_neg < error_pos:
                weaks.append(weakclf_neg)
                errors.apppend(error_neg)
            else :
                weaks.append(weakclf_pos)
                errors.append(error_pos)

        min_error = 1
        for i in range(0,len(errors)):
            if errors[i] < min_error: 
              min_error = errors[i]
              min_error_index = i
        bestClf = weaks[min_error_index]
        bestError = min_error
        return bestClf, bestError
    
    # 0.595
    def custom_selectBest_v1(self, featureVals, iis, labels, features, weights): 

        errors = []
        weaks = []

        # Using each feature to establish a weakclassfier
        # The goal is to find the best classifier
        for feature in features:  
          result = []
          weak = WeakClassifier(feature)
          weaks.append(weak)

          # For every data in the dataset
          for i in iis:
            result.append(weak.classify(i))
          miss = [int(i != j) for i, j in zip(result, labels)]
          error = np.dot(weights, miss)
          errors.append(error)
        
        # Find out the smallest error
        min_error = 1
        for i in range(0,len(errors)):
          if errors[i] < min_error: 
            min_error = errors[i]
            min_error_index = i
        
        bestClf = weaks[min_error_index]
        bestError = min_error
        return bestClf, bestError
    
    def classify(self, image):
        """
        Classifies an image
          Parameters:
            image: A numpy array with shape (m, n). The shape (m, n) must be
              the same with the shape of training images.
          Returns:
            1 if the image is positively classified and 0 otherwise
        """
        total = 0
        ii = utils.integralImage(image)
        for alpha, clf in zip(self.alphas, self.clfs):
            total += alpha * clf.classify(ii)
        return 1 if total >= 0.5 * sum(self.alphas) else 0
    
    def save(self, filename):
        """
        Saves the classifier to a pickle
          Args:
            filename: The name of the file (no file extension necessary)
        """
        with open(filename+".pkl", 'wb') as f:
            pickle.dump(self, f)

    @staticmethod
    def load(filename):
        """
        A static method which loads the classifier from a pickle
          Args:
            filename: The name of the file (no file extension necessary)
        """
        with open(filename+".pkl", 'rb') as f:
            return pickle.load(f)